# TorrentSpyder: Retrieve Torrent Download History by IP Address

**TorrentSpyder** is a command-line utility designed to retrieve Torrent Download History based on a specified IP address. This tool is valuable for educational and security assessment purposes, allowing users to uncover relevant information about the IP's download activities.

## **Features**

- **Torrent Download History Retrieval**: Gathers detailed information on torrent download activities associated with a specified IP address.
- **HTML Report Generation**: Produces a clean and organized HTML file for users to easily view and analyze the retrieved download history.
- **User-Friendly Interface**: Offers intuitive prompts and colour-coded outputs, requiring minimal effort from the user to navigate and operate the tool.
- **Cross-Platform Compatibility**: Primarily designed for Linux, with potential for adaptation to Windows systems.
- **File Management**: Provides users with the option to delete the generated HTML report after processing for improved organization.

## **Prerequisites**

- **C++ Compiler** (g++)
- **Perl**
- **Wget**

## **Installation**

1. **Clone the repository:**
   
   ```bash
   git clone https://github.com/AnonKryptiQuz/TorrentSpyder.git
   cd TorrentSpyder
   ```

2. **Install required packages:**

- **Debian/Ubuntu**: 
   ```bash
   sudo apt install g++ perl wget
   ```

- **Fedora**: 
   ```bash
   sudo dnf install gcc-c++ perl wget
   ```

- **Arch Linux**: 
   ```bash
   sudo pacman -S gcc perl wget
   ```

- **OpenSUSE**: 
   ```bash
   sudo zypper install gcc-c++ perl wget
   ```

3. **Compile the source code:**

   ```bash
   g++ -o TorrentSpyder TorrentSpyder.cpp
   ```

## **Usage**

1. **Run the tool:**

   ```bash
   ./TorrentSpyder
   ```

2. **Follow the prompts:**

## **Disclaimer**

- **Educational Purposes Only**: TorrentSpyder is intended for educational and research use. The tool should not be used for illegal or malicious activities. It is the user’s responsibility to ensure compliance with local laws and regulations.

- **Accuracy Not Guaranteed**: While TorrentSpyder aims to provide useful data, the accuracy of the results may vary. The tool relies on third-party data sources, which may not always be up-to-date or accurate. Use this tool with caution, and verify the information through additional means if necessary.

## **Credits**

This tool uses open-source projects, and we give full credit to the original developers:

- **IKnowWhatYouDownload** by [iknowtorrents](https://x.com/iknowtorrents)

## **Author**

**Created by:** [AnonKryptiQuz](https://AnonKryptiQuz.github.io/)
