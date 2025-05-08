#include <iostream>   // For std::cout, std::cin, std::endl, std::flush
#include <string>     // For std::string
#include <limits>     // (Optional, for clearing cin buffer more safely)
#include <cstdlib>    // For system() in clearScreen()

#include "crew_manager.hpp"

void Game::manageCrew()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Manage Crew Menu           " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "Crew Management System\n";
    std::cout << "1. View Crew List\n";
    std::cout << "2. Assign Roles\n";
    std::cout << "3. Dismiss Crew Member\n";
    std::cout << "4. Add Crew Member\n";
    std::cout << "5. View Crew Status\n";
    std::cout << "6. Return to Main Menu\n";
    std::cout << "=====================================" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        viewCrewList();
        break;
    case 2:
        assignRoles();
        break;
    case 3:
        dismissCrewMember();
        break;
    case 4:
        addCrewMember();
        break;
    case 5:
        viewCrewStatus();
        break;
    case 6:
        displayMainMenu();
        break;
    default:
        std::cout << "Invalid choice. Returning to Manage Crew Menu...\n";
        manageCrew();
        break;
    }
}

void Game::addCrewMember()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "          Add Crew Member             " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Implement Crew Member Addition]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew(); // Return to the manage crew menu
}

void Game::assignRoles()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Assign Roles               " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Implement Role Assignment]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}

void Game::viewCrewList()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "             Crew List                " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Display Crew List]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}

void Game::dismissCrewMember()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "         Dismiss Crew Member          " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Implement Crew Member Dismissal]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}

void Game::viewCrewStatus()
{
    clearScreen();
    std::cout << "=====================================" << std::endl;
    std::cout << "           Crew Status                " << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "[TODO: Display Crew Status]\n";
    std::cout << "\nPress Enter to return to Manage Crew Menu.";
    std::cin.ignore();
    std::cin.get();
    manageCrew();
}
