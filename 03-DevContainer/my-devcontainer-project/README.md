# My DevContainer Project

## Overview
This project is set up to provide a development environment using a Docker container. It includes all necessary tools and libraries for building and running C applications.

## Getting Started

### Prerequisites
- Docker must be installed on your machine.
- Visual Studio Code with the Remote - Containers extension.

### Setting Up the Development Container
1. Clone the repository to your local machine.
2. Open the project folder in Visual Studio Code.
3. When prompted, reopen the folder in the container. This will build the Docker image defined in the `.devcontainer/Dockerfile` and set up the environment.

### Project Structure
```
my-devcontainer-project
├── .devcontainer
│   ├── devcontainer.json
│   └── Dockerfile
├── .vscode
│   ├── settings.json
│   └── extensions.json
├── src
│   └── main.c
├── Makefile
└── README.md
```

### Building the Project
To build the project, run the following command in the terminal:
```
make
```

### Running the Application
After building, you can run the application with:
```
./your_executable_name
```

### Contributing
Feel free to submit issues or pull requests if you have suggestions or improvements.

### License
This project is licensed under the MIT License. See the LICENSE file for details.