# Todo CLI - A Simple Command-Line Task Manager in C
[![Status](https://img.shields.io/badge/status-in%20progress-yellow.svg)]()

## Description
Todo CLI is a command-line application written in C for managing tasks. The program allows users to add, list, mark as completed, and delete tasks. The tasks are stored persistently in a text file for later retrieval. It provides a simple and efficient way to manage tasks directly from the terminal.

## Features

- **Add tasks**: Users can add tasks with a description and priority (low, medium, high).
- **List tasks**: View all tasks, with the ability to filter by status (pending/completed) and priority.
- **Mark tasks as completed**: Users can mark tasks as completed.
- **Delete tasks**: Users can delete tasks by ID with a confirmation prompt.
- **Persistent storage**: Tasks are stored in a text file (`tasks.txt`) for persistent data storage.
  
## Requirements

- **Language**: C (C99 or higher)
- **Platform**: Linux and macOS (Windows optional)
- **Storage**: Text file (`tasks.txt`)

## Usage

### 1. Add a Task
To add a new task with a description and priority, run:
```bash
todo-cli add "Task description" --priority [low|medium|high]
```
Example:
```bash
todo-cli add "Review documents" --priority high
```

### 2. List Tasks
To list all tasks, run:
```bash
todo-cli list
```

Example output:
```bash
ID  Description               Priority  Status
1   Review documents          high      pending
2   Attend meeting with John  medium    pending
3   Prepare presentation      low       pending
```

You can filter tasks by status and priority:

```bash
todo-cli list --status completed
```

```bash
todo-cli list --priority high
```

### 3. Mark a Task as Completed
To mark a task as completed by its ID, run:

```bash
todo-cli done <task_id>
```

Example:
```bash
todo-cli done 1
```

### 4. Delete a Task
To delete a task by its ID, run:

```bash
todo-cli delete <task_id>
```

Example:
```bash
todo-cli delete 1
```
The program will ask for confirmation:

```bash
Are you sure you want to delete task [1]? (y/n)
```
### 5. File Storage Format
The tasks are stored in a text file (`tasks.txt`) in the following format:
```
ID|Description|Priority|Status
```
Example of `tasks.txt`:
```
1|Review documents|high|pending
2|Attend meeting with John|medium|pending
3|Prepare presentation|low|pending
```

## 🚀 Usage

### 1. Compilation
To compile the project, run:

```bash
make
```

This will create an executable file named `todo-cli` in the `bin` directory.

### 2. Execution
Once compiled, you can run the program with:

```bash
./build/todo-cli
```

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Acknowledgments
- Thanks to ChatGPT for the idea and defining requirements for this project.