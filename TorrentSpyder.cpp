#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <regex>
#include <csignal>

using namespace std;

const string RED = "\033[0;31m";
const string GREEN = "\033[0;32m";
const string YELLOW = "\033[0;33m";
const string BLUE = "\033[0;34m";
const string MAGENTA = "\033[0;35m";
const string CYAN = "\033[0;36m";
const string WHITE = "\033[0;37m";
const string NC = "\033[0m";

void cleanup(int signum) {
    cout << endl << RED << "Program terminated by the user." << NC << endl;
    exit(1);
}

void removeUnwantedHTML(const string& filePath) {
    string commands[] = {
        "perl -0777 -pi -e 's|<div class=\"col-md-12 text-center\">.*?</div>||gs' " + filePath,
        "perl -0777 -pi -e 's|<a class=\"twitter-follow-button\">.*?</div>||gs' " + filePath,
        "perl -0777 -pi -e 's|Check your IP address [0-9]+\\.[0-9]+\\.[0-9]+\\.[0-9]+||gs' " + filePath,
        "perl -0777 -pi -e 's|<div class=\"padding-block\">.*?</div>||gs' " + filePath,
        "perl -0777 -pi -e 's|<nav class=\"navbar navbar-default\">.*?</nav>||gs' " + filePath,
        "perl -0777 -pi -e 's|<ul class=\"nav navbar-nav\">.*?</ul>||gs' " + filePath,
        "perl -0777 -pi -e 's|<form class=\"navbar-form navbar-left\".*?</form>||gs' " + filePath,
        "perl -0777 -pi -e 's|<img alt=\"Brand\".*?>||gs' " + filePath
    };

    for (const auto& command : commands) {
        if (system(command.c_str()) != 0) {
            cout << RED << "Error executing command: " << command << NC << endl;
        }
    }
}

int main() {
    signal(SIGINT, cleanup);

    system("clear");

    cout << " _____                          _   __                 _           " << endl;
    cout << "/__   \\___  _ __ _ __ ___ _ __ | |_/ _\\_ __  _   _  __| | ___ _ __ " << endl;
    cout << "  / /\\/ _ \\| '__| '__/ _ \\ '_ \\| __\\ \\| '_ \\| | | |/ _` |/ _ \\ '__|" << endl;
    cout << " / / | (_) | |  | | |  __/ | | | |__\\ \\ |_) | |_| | (_| |  __/ |   " << endl;
    cout << " \\/   \\___/|_|  |_|  \\___|_| |_|\\__\\__/ .__/ \\__, |\\__,_|\\___|_|   " << endl;
    cout << "                                      |_|    |___/                 " << endl;
    cout << "                                                                   " << endl;
    cout << GREEN << "Unveil the IP's Hidden Secrets with TorrentSpyder - AnonKryptiQuz\n" << NC << endl;

    string userIP;
    cout << "Enter the IP address: ";
    cin >> userIP;

    if (!regex_match(userIP, regex(R"(^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$)"))) {
        cout << RED << "Invalid IP address. Please enter a valid IP." << NC << endl;
        return 1;
    }

    string command = "wget -q -O downloaded_page.html \"https://iknowwhatyoudownload.com/en/peer/?ip=" + userIP + "\"";
    if (system(command.c_str()) != 0) {
        cout << RED << "Unable to download webpage." << NC << endl;
        return 1;
    }

    ifstream file("downloaded_page.html");
    if (!file.is_open()) {
        cout << RED << "Unable to open downloaded HTML file." << NC << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string html = buffer.str();
    file.close();

    removeUnwantedHTML("downloaded_page.html");

    cout << GREEN << "Webpage downloaded successfully. Opening in default web browser..." << NC << endl;
    system("xdg-open downloaded_page.html 2>/dev/null");

    cout << "Do you want to delete the downloaded page? (y-n, Press enter for Y): ";
    string deleteChoice;
    cin.ignore();
    getline(cin, deleteChoice);

    if (deleteChoice != "N" && deleteChoice != "n") {
        if (remove("downloaded_page.html") != 0) {
            cout << RED << "Error deleting file." << NC << endl;
        } else {
            cout << YELLOW << "File deleted." << NC << endl;
        }
    } else {
        cout << YELLOW << "File not deleted." << NC << endl;
    }

    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}
