#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

// Define the structure for a task
typedef struct Task {
    char description[MAX_LEN];
    int priority;         // 1 = High, 2 = Medium, 3 = Low
    struct tm dueDate;    // Due date for the task
    int completed;        // 0 = not completed, 1 = completed
    struct Task* next;
} Task;

Task* head = NULL;

// Function to add a task
void addTask(char* desc) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    strcpy(newTask->description, desc);
    
    // Ask user for priority
    printf("Enter priority (1 = High, 2 = Medium, 3 = Low): ");
    scanf("%d", &newTask->priority);
    
    // Ask user for due date
    printf("Enter due date (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &newTask->dueDate.tm_mday, &newTask->dueDate.tm_mon, &newTask->dueDate.tm_year);
    newTask->dueDate.tm_year -= 1900; // Adjust year for tm structure
    newTask->dueDate.tm_mon -= 1; // Adjust month for tm structure

    // Set completed status to 0 (not completed)
    newTask->completed = 0;
    
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newTask;
    }

    printf("Task added successfully.\n");
}

// Function to view all tasks
void viewTasks() {
    if (head == NULL) {
        printf("No tasks in the list.\n");
        return;
    }

    Task* temp = head;
    int i = 1;
    printf("\nTo-Do List:\n");
    while (temp != NULL) {
        printf("%d. %s\n", i++, temp->description);
        printf("   Priority: %d, Due Date: %02d-%02d-%d, ", 
                temp->priority, temp->dueDate.tm_mday, temp->dueDate.tm_mon + 1, temp->dueDate.tm_year + 1900);
        if (temp->completed) {
            printf("Status: Completed\n");
        } else {
            printf("Status: Pending\n");
        }
        temp = temp->next;
    }
}

// Function to mark a task as complete
void markTaskComplete(int taskNum) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Task* temp = head;
    int i = 1;
    while (temp != NULL && i < taskNum) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid task number.\n");
        return;
    }

    temp->completed = 1; // Mark the task as completed
    printf("Task marked as completed.\n");
}

// Function to delete a task by number
void deleteTask(int taskNum) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Task* temp = head;
    Task* prev = NULL;

    int i = 1;
    while (temp != NULL && i < taskNum) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid task number.\n");
        return;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Task deleted successfully.\n");
}

// Function to free all tasks
void clearAllTasks() {
    Task* temp = head;
    while (temp != NULL) {
        Task* toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
    head = NULL;
    printf("All tasks cleared.\n");
}


int main() {
    int choice;
    char desc[MAX_LEN];
    int taskNum;

    while (1) {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Complete\n");
        printf("4. Delete Task\n");
        printf("5. Clear All Tasks\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                fgets(desc, MAX_LEN, stdin);
                desc[strcspn(desc, "\n")] = '\0'; // Remove newline
                addTask(desc);
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                printf("Enter task number to mark as complete: ");
                scanf("%d", &taskNum);
                markTaskComplete(taskNum);
                break;

            case 4:
                printf("Enter task number to delete: ");
                scanf("%d", &taskNum);
                deleteTask(taskNum);
                break;

            case 5:
                clearAllTasks();
                break;

            case 6:
                printf("Exiting...\n");
                clearAllTasks();  // Free memory before exit
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
