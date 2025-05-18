package starship

import java.nio.file.Paths
import scala.util.Try


object runner {
    def main(args: Array[String]) = {
        new Game().run()
    }
}

class Game(
    var playerName: String = "Captain",
    var shipName: String = "Enterprise",
    var playerPosition: Int = 0,
    var _isRunning: Boolean = true
) {
    val loaver = new Loaver(Paths.get("saves"))

    var captainsLog = Seq[String]()
    var score = 0
    var crewSize = 0
    var numPlayers = 0
    var hullIntegrity = 0
    var firstOfficer = ""
    var secondOfficer = ""
    var chiefEng = ""
    var chiefSecurity = ""
    var chiefScience = ""
    var chiefMed = ""
    var chiefTac = ""
    var currentLocation = ""
    var shieldStatus = ""
    var shieldStrength = ""

    def stop(): Unit = _isRunning = false
    def isRunning(): Boolean = _isRunning


    def run(): Unit =
        displayWelcomeScreen()
        displayMainMenu()
        println("\nExiting. Goodbye!\n")


    def displayWelcomeScreen(): Unit =
        val msg = 
            s"""=====================================
                |          StarshipAscension          
                |=====================================
                |Welcome aboard, Captain $playerName
                |A galaxy of adventure awaits you, Captain!
                |Prepare to explore the stars and achieve ascension.""".stripMargin
        clearAndDisplayWithContinue(msg)


    def addToCaptainsLog(entry: String): Unit =
        captainsLog = captainsLog :+ entry
        println("Entry added to Captain's Log: " + entry)


    def displayMainMenu(): Unit =
        executeMenu(
            "Main Menu", 
            Some("Exit"),
            Array(
                ("Start New Game", () => processPlayerCommand()),
                ("Continue Game", () => processPlayerCommand()),
                ("Save Game", () => saveGame()),
                ("Load Saved Game", () => loadGame()),
                ("Captain's Log", 
                    () => {
                        clearScreen()
                        println("Initializing Captain's Log...\n")

                        val progress = 0
                        val total = 100

                        for
                            progress <- 0 to total by 10
                        do
                            val barWidth = 50
                            val filledWidth = (progress * barWidth) / total
                            println(s"[${"=" * filledWidth}${" " * (barWidth - filledWidth)}] ${(progress * 100) / total}%")
                            Thread.sleep(200)

                        println()
                        println("Captain's Log initialized successfully.\n")
                        displayCaptainsLog()

                        // Display mock Captain's Log entries (for testing)
                        promptForLine("""[TODO: Implement Captain's Log functionality]
                            |
                            |Press Enter to return to the Main Menu.""".stripMargin)
                        ()
                    }
                ),
                ("Mission Briefing", 
                    () => {
                        promptForLine("""
                            Displaying mission briefing...
                            |[TODO: Implement Mission Briefing]
                            |
                            |Press Enter to return to the Main Menu.""".stripMargin)
                        clearScreen()
                        // TODO: Implement mission briefing functions
                        // createMissionBriefing();
                        // saveMissionBriefing();
                        // loadMissionBriefing();
                        // displayMissionBriefing();
                    }
                ),
                ("Ship Systems Overview", () => {
                    clearScreen()
                    displayShipSystemsOverview()
                }),
                ("Help", () => displayHelpMenu()),
                ("Setup Game", () => displaySetupMenu()),
                ("Credits", () => displayCredits()),
                ("Resume Last Mission", () => ()),
                ("Tactical Overview", () => ()),
                ("Manage Crew", () => manageCrew())
            )
        )


    def displayCaptainsLog(): Unit =
        println("=====================================")
        println("          Captain's Log              ")
        println("=====================================")

        if captainsLog.isEmpty then
            println("The Captain's Log is empty. No entries recorded yet.")
        else
            captainsLog.zipWithIndex.foreach{
                case (msg, n) => println(s"${n + 1}. $msg")
            }


    def displayHelpMenu(): Unit =
        clearAndDisplayWithContinue("""=====================================
            |               Help Menu              
            |=====================================
            |Welcome to StarshipAscension!
            |Here are some tips to help you get started:
            |- Use 'move' to explore the galaxy.
            |- Use 'quit' to end the game.
            |- Complete missions to gain points and advance.""".stripMargin)


    def displaySetupMenu(): Unit =
        clearScreen()
        println("=====================================")
        println("            Setup Game Menu           ")
        println("=====================================")
        println("Configure your game settings here.\n")

        numPlayers = promptForInt("Enter the number of players: ").getOrElse(1)

        shipName = promptForLine("Enter your ship's name: ")
        playerName = promptForLine("Enter your name, Captain: ")
        firstOfficer = promptForLine("Enter your First Officer's name: ")
        secondOfficer = promptForLine("Enter your Second Officer's name: ")
        chiefSecurity = promptForLine("Enter your Chief Security Officer's name: ")
        chiefMed = promptForLine("Enter your Chief Medical Officer's name: ")
        chiefEng = promptForLine("Enter your Chief Engineer's name: ")
        chiefTac = promptForLine("Enter your Chief Tactical Officer's name: ")
        chiefScience = promptForLine("Enter your Chief Science Officer's name: ")

        val manageCrewChoice = promptForLine("Would you like to manage your crew, captain? (yes/no): ")
        if manageCrewChoice == "yes" || manageCrewChoice == "y" then
            println("You can manage your crew in the Manage Crew Menu.\n")
            manageCrew()
            clearScreen()
        else if manageCrewChoice == "no" || manageCrewChoice == "n" then
            println("You can manage your crew later in the game.\n")
            clearScreen()

        clearScreen()

        promptForLine(s"""
            |Configuration complete!
            |
            |Players: $numPlayers
            |Ship Name: $shipName
            |Captain: $playerName
            |
            |Press Enter to return to the Main Menu.""".stripMargin)
        // TODO: Implement saveSetup function to save the setup
        // saveSetup()
        clearScreen()


    def displayShipSystemsOverview(): Unit =
        val msg = 
            s"""=====================================
            |         Ship Systems Overview        
            |=====================================
            |Ship Name: $shipName
            |Captain:   $playerName
            |First Officer: $firstOfficer
            |Second Officer: $secondOfficer
            |Chief Security Officer: $chiefSecurity
            |Chief Medical Officer: $chiefMed
            |Chief Engineer: $chiefEng
            |Chief Tactical Officer: $chiefTac
            |Current Location: $currentLocation
            |Current Position: $playerPosition
            |Ship Status:  Online
            |Mission Status: In Progress
            |Crew Size: $crewSize
            |=====================================
            |Power Core:  Online (85% capacity)
            |Engines:     Operational (Warp Speed: 3.5)
            |Shields Status: $shieldStatus
            |Sheilds Strength: $shieldStrength
            |Hull Integrity:$hullIntegrity
            |Weapons:     Armed (Photon Torpedoes: 8 remaining)
            |Sensors:     Calibrated (Range: 20,000 km)
            |Life Support: Nominal (Oxygen: 95%)
            |=====================================
            |Mission Objectives:
            |- Explore the Alpha Centauri System
            |- Deliver supplies to Station Delta
            |- Respond to distress signal near Proxima Centauri
            |=====================================
            |Cargo Bay:
            |- Medical Supplies: 20 crates
            |- Food Rations:     15 crates
            |- Exotic Minerals:  5 crates
            |=====================================
            |Ship's Log:
            |- Last docked: Starbase 23
            |- Current Location: $currentLocation
            |- Distress signals received: 1
            |=====================================""".stripMargin
        clearAndDisplayWithContinue(msg)


    def displayCredits(): Unit =
        clearAndDisplayWithContinue("""=====================================
            |               Credits               
            |=====================================
            |StarshipAscension was created by Gregory K. Bowne!
            |Special thanks to our interstellar community!""".stripMargin)


    def saveGame(): Unit =
        clearScreen()
        val menuChoice = promptForInt("""=====================================
            |           Save Game Menu             
            |=====================================
            |Choose a format to save your game:
            |1. Plain Text (.txt)
            |2. JSON (.json)
            |3. XML (.xml)
            |4. Binary (.dat)""".stripMargin).getOrElse(-1)

        var fileName = "saved_game"
        val data = SaveData(playerName, playerPosition, score)

        menuChoice match
            case 1 =>
                fileName += ".txt"
                loaver.saveAsPlainText(fileName, data)
            case 2 =>
                fileName += ".json"
                loaver.saveAsJson(fileName, data)
            case 3 =>
                fileName += ".xml"
                loaver.saveAsXML(fileName, data)
            case 4 =>
                fileName += ".dat"
                loaver.saveAsBinary(fileName, data)
            case _ =>
                println("Invalid choice. Returning to menu...\n")
                return

        promptForLine(s"Game saved successfully to $fileName!\nPress Enter to return to the Main Menu.")


    def loadGame(): Unit =
        clearScreen()
        val choice = promptForInt(s"""=====================================
            |           Load Game Menu             
            |=====================================
            |Choose the format of your saved game:
            |1. Plain Text (.txt)
            |2. JSON (.json)
            |3. XML (.xml)
            |4. Binary (.dat)
            |""".stripMargin).getOrElse(-1)

        println("Saved files:")
        loaver.listSaveFiles().foreach(f => println(f.getFileName()))
        println()

        val fileName = promptForLine("Enter the name of the saved game file (with extension): ")

        choice match
            case 1 =>
                loaver.loadFromPlainText(fileName).foreach{
                    case SaveData(name, pos, loadedScore) =>
                        playerName = name
                        playerPosition = pos
                        score = loadedScore
                }

            case 2 =>
                loaver.loadFromJson(fileName).foreach{
                    case SaveData(name, pos, loadedScore) =>
                        playerName = name
                        playerPosition = pos
                        score = loadedScore
                }

            case 3 =>
                loaver.loadFromXML(fileName).foreach{
                    case SaveData(name, pos, loadedScore) =>
                        playerName = name
                        playerPosition = pos
                        score = loadedScore
                }

            case 4 =>
                loaver.loadFromBinary(fileName).foreach{
                    case SaveData(name, pos, loadedScore) =>
                        playerName = name
                        playerPosition = pos
                        score = loadedScore
                }

            case _ =>
                println("Invalid choice. Returning to menu...\n")
                return

        promptForLine("\nPress Enter to return to the Main Menu.")


    def executeMenu(title: String, returnMsg: Option[String], options: Array[(String, () => Unit)]): Unit =
        if isRunning() then
            println()
            val msg = s"""
                |=====================================
                |           $title           
                |=====================================
                |${options.zipWithIndex.map{ case ((s, f), i) => s"${i + 1}. $s"}.mkString("\n")}
                |${returnMsg.foldLeft(""){ case (acc, msg) => s"${options.length + 1}. ${msg}" }}
                |=====================================
                |Enter your choice: """.stripMargin

            promptForInt(msg).getOrElse(-1) match
                case n if returnMsg.isDefined && n == options.length + 1 => ()
                case n if n >= 1 && n <= options.length =>
                    options(n - 1)(1)()
                    executeMenu(title, returnMsg, options)
                case _ =>
                    println("Invalid choice.")
                    executeMenu(title, returnMsg, options)


    def manageCrew(): Unit =
        executeMenu(
            "Manage Crew Menu", 
            Some("Return to Main Menu"),
            Array(
                ("View Crew List", () => viewCrewList()),
                ("Assign Roles", () => assignRoles()),
                ("Dismiss Crew Member", () => dismissCrewMember()),
                ("Add Crew Member", () => addCrewMember()),
                ("View Crew Status", () => viewCrewStatus())
            )
        )


    def addCrewMember(): Unit =
        clearAndDisplayWithContinue("""=====================================
            |          Add Crew Member             
            |=====================================
            |[TODO: Implement Crew Member Addition]""".stripMargin)


    def assignRoles(): Unit =
        clearAndDisplayWithContinue("""=====================================
            |           Assign Roles               
            |=====================================
            |[TODO: Implement Role Assignment]""".stripMargin)


    def viewCrewList(): Unit =
        clearAndDisplayWithContinue("""=====================================
            |             Crew List                
            |=====================================
            |[TODO: Display Crew List]""".stripMargin)


    def dismissCrewMember(): Unit =
        clearAndDisplayWithContinue("""=====================================
            |         Dismiss Crew Member         
            |=====================================
            |[TODO: Implement Crew Member Dismissal]""".stripMargin)


    def viewCrewStatus(): Unit =
        clearAndDisplayWithContinue("""=====================================
            |           Crew Status                
            |=====================================
            |[TODO: Display Crew Status]""".stripMargin)


    def processPlayerCommand(): Unit =
        if isRunning() then
            println()
            val command = promptForLine("Enter your command (move, quit, menu, scan, help): ").toLowerCase

            command match
                case "move" | "" =>
                    playerPosition += 1
                    println(s"You moved to position $playerPosition.")
                    printGameState()
                    processPlayerCommand()

                case "quit" | "q" => stop()
                case "menu" | "m" => ()

                case "scan" | "s" =>
                    println("Scanning the surrounding area... No threats detected!")
                    // scanField(playingField, playerX, playerY);
                    printGameState()
                    processPlayerCommand()

                case "help" | "h" => displayHelpMenu()

                case _ => println("Invalid command. Try again!")


    def printGameState(): Unit =
        if playerPosition >= 10 then
            println(s"Congratulations, Captain $playerName! You've completed your mission.")
            stop()
        else
            println("Exploring new galaxies...")
            println(s"""=============================
                |Rendering Current Game State
                |=============================
                |Player Position: $playerPosition
                |Keep exploring the galaxy, Captain $playerName!
                |=============================""".stripMargin)


    def clearAndDisplayWithContinue(msg: String): Unit =
        clearScreen()
        promptForLine(s"""$msg
            |
            |Press Enter to continue.""".stripMargin)


    def promptForLine(msg: String): String =
        println(msg)
        io.StdIn.readLine()


    def promptForInt(msg: String): Option[Int] =
        println(msg)
        Try(io.StdIn.readLine().toInt).toOption


    def clearScreen(): Unit = print("\n" * 50)

}

// TODO: Implement scanField function to scan the field
// void Game::scanField(const std::vector<std::vector<char>> &field, int playerX, int playerY)
// {
//     std::cout << "Scanning the surrounding area...\n";

//     for (int x = std::max(0, playerX - 1); x <= std::min((int)field.size() - 1, playerX + 1); ++x)
//     {
//         for (int y = std::max(0, playerY - 1); y <= std::min((int)field[x].size() - 1, playerY + 1); ++y)
//         {
//             if (field[x][y] != ' ' && !(x == playerX && y == playerY))
//             {
//                 std::cout << "Found: " << field[x][y] << " at (" << x << ", " << y << ")\n";
//             }
//         }
//     }
// }
