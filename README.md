# CA: Command Line Utility 🚀  

CA is a versatile Linux command line utility designed to streamline file manipulation, system information retrieval, and text processing tasks. While it humbly admits it might not be the fastest or most efficient, it delivers reliability and ease of use, enhancing your command line experience.  

---

## 🌟 Features  

### File Operations  
- **View File Content**:  
  - `ca sf <filePath>` → Display file contents.  
  - `ca sf-l <filePath>` → Display file contents with line numbers.  
- **Copy Files**:  
  - `ca cp <SourceFile> <DestinationFile>` → Copy files.  
- **File Information**:  
  - `ca finfo <FileName>` → Retrieve details of a specific file.  
- **Count Lines**:  
  - `ca lines <FileName>` → Count the number of lines in a file.  
- **Create Files**:  
  - `ca c <FileName>` → Create an empty file.  
- **Delete Files**:  
  - `ca -del <FileName>` → Delete a specified file.  

### System Utilities  
- **Print Custom Text**:  
  - `ca -p <text_separated_by_underscores>` → Print formatted text.  
- **System Information**:  
  - `ca -sysinfo` → Display system details.  
  - `ca -sysS` → Check storage capacity.  
- **Date and Time**:  
  - `ca -time` → Show the current date and time.  

---

## ⚙️ Installation  

Follow these simple steps to install and start using **CA**:  

1. Clone the repository:  
   ```bash
   git clone https://github.com/dishan1223/ca.git
2. Navigate to the repository folder:
   ```bash
   cd ca
3. Make the installer executable:
   ```bash
   chmod +x install.sh
4. Run the installer:
   ```bash
   ./install.sh
5. Start using CA:
   ```bash
   ca
## 📝 Notes  

- **CA** is designed to simplify your workflow but may not always be the most optimized solution for advanced users.  
- Ideal for quick and straightforward operations on the command line.  
- Give **CA** a try and enjoy an honest, user-friendly command line experience! 😊  
