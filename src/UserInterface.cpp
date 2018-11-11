#include "../include/UserInterface.h"
#include "../include/FileWriter.h"
#include "../include/LiveStream.h"
#include "../include/MovieFacade.h"
#include "../include/InputValidator.h"
#include "../include/MoviePrinter.h"
#include <iostream>
#include <fstream>
#include <map>

UserInterface::UserInterface() : end(0) {}

void UserInterface::showOptions() {
    eventsReminder.remindeInNext24H();
    std::cout << "\n1.Add new\n"
        << "2.Add series to following\n"
        << "3.Show all\n"
        << "4.Remove series from following\n"
        << "5.Remove\n"
        << "6.Update\n"
        << "7.Propose something to watching\n"
        << "8.Print statistics of following series\n"
        << "9.Show info about film\n"
        << "10.Show all following series\n"
        << "11.Exit\n";
}

void UserInterface::getAction() {
    action = InputValidator::cinInt();
}

void UserInterface::performAction() {
    switch (action) {
        case 1: movieFacade -> addFilm(); break;
        case 2: movieFacade -> addSeriesToFollowing(); break;
        case 3: MoviePrinter::showAllMovies(); break;
        case 4: movieFacade -> removeFollowing(); break;
        case 5: movieFacade -> removeMovie(); break;
        case 6: movieFacade -> update(); break;
        case 7: movieProposer.proposeSomethingToWatch(); break;
        case 8: statisticMaker.showAll(); break;
        case 9: MoviePrinter::showOne();break;
        case 10: MoviePrinter::showAllFollowing(); break;
        case 11: end = true; break;
        default: break;
    }
}

void UserInterface::start() {
    movieFacade ->loadDatabase();
    while(!end) {
        showOptions();
        getAction();
        performAction();
        wait();
    }
}

void UserInterface::wait() {
    std::cout << "Press enter to continue ...";
    std::cin.get();
}
