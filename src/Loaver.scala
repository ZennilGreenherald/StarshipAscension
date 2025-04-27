package starship

import java.io.{DataInputStream, DataOutputStream}
import java.nio.file.{Path, Paths, Files, FileSystems}
import java.nio.charset.StandardCharsets
import scala.jdk.CollectionConverters._
import scala.xml.XML
import scala.util.Try

import upickle.default.*


case class SaveData(name: String, position: Int, score: Int) derives ReadWriter

class Loaver(saveDirPath: Path) {

    if !Files.exists(saveDirPath) then
        Files.createDirectories(saveDirPath)

    def listSaveFiles(): Iterator[Path] = Files.list(saveDirPath).iterator().asScala.filter(Files.isRegularFile(_))


    def saveAsPlainText(fileName: String, data: SaveData): Unit =
        val saveString = s"""name:${data.name}
            |position:${data.position}
            |score:${data.score}
            |""".stripMargin

        Files.write(saveDirPath.resolve(fileName), saveString.getBytes(StandardCharsets.UTF_8))


    def saveAsJson(fileName: String, data: SaveData): Unit =
        Files.write(saveDirPath.resolve(fileName).normalize(), write(data).getBytes(StandardCharsets.UTF_8))


    def saveAsXML(fileName: String, data: SaveData): Unit =
        val xmlString = s"""<Game>
            |<Player>
            |<Name>${data.name}</Name>
            |<Position>${data.position}</Position>
            |</Player>
            |<Score>${data.score}</Score>
            |</Game>""".stripMargin

        Files.write(saveDirPath.resolve(fileName), xmlString.getBytes(StandardCharsets.UTF_8))


    def saveAsBinary(fileName: String, data: SaveData): Unit =
        val dos = new DataOutputStream(Files.newOutputStream(saveDirPath.resolve(fileName)))
        try
            dos.writeInt(data.position)
            dos.writeInt(data.score)
            val bytes = data.name.getBytes()
            dos.writeInt(bytes.length)
            dos.write(bytes, 0, bytes.length)
            println(s"Game saved successfully to: $fileName")
        catch
            case e: Exception => println(s"Error saving game: $e")
        finally
            dos.close()


    def loadFromPlainText(fileName: String): Try[SaveData] =
        val source = scala.io.Source.fromFile(saveDirPath.resolve(fileName).toFile)
        try
            val lineMap: Map[String, String] = source.getLines.filter(!_.trim().isEmpty).map(_.split(":")).map{ case Array(x, y) => (x, y) }.toMap
            Try(SaveData(lineMap("name"), lineMap("position").toInt, lineMap("score").toInt))
        finally
            source.close()


    def loadFromJson(fileName: String): Try[SaveData] =
        val source = scala.io.Source.fromFile(saveDirPath.resolve(fileName).toFile)
        try
            Try(read[SaveData](source.mkString))
        finally
            source.close()


    def loadFromXML(fileName: String): Try[SaveData] =
        val elem = XML.loadFile(saveDirPath.resolve(fileName).toFile)

        val datas = 
            for scoreNode <- elem \ "Score"
                score <- scoreNode.child
                playerNode <- elem \ "Player"
                nameNode <- playerNode \ "Name"
                name <- nameNode.child
                positionNode <- playerNode \ "Position"
                position <- positionNode.child
            yield SaveData(name.text, position.text.toInt, score.text.toInt)
        Try(datas.head)


    def loadFromBinary(fileName: String): Try[SaveData] =
        val dis = new DataInputStream(Files.newInputStream(saveDirPath.resolve(fileName)))
        try
            Try({
                val position = dis.readInt()
                val score = dis.readInt()
                val name = {
                    val nameLength = dis.readInt()
                    val bytes = Array.ofDim[Byte](nameLength)
                    dis.read(bytes)
                    new String(bytes, java.nio.charset.StandardCharsets.UTF_8)
                }
                SaveData(name, position, score)
            })
        finally
            dis.close()
}
