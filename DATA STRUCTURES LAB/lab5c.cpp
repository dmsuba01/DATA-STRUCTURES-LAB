//ROUND ROBIN SCHEDULING ALGORITHM
#include<iostream>
using namespace std;

class RoundRobinScheduler {
private:
    struct Process {
        int processID;
        int remainingTime;
        struct Process* next;
    } *head;

    int timeSlice;  // Fixed time slot for each process

public:
    RoundRobinScheduler(int slot) {
        head = nullptr;
        timeSlice = slot;
    }

    void insertProcess(int processID, int execTime);
    void execute();
    void display();
    int getMenu();
    bool isEmpty();
};

int main() {
    int timeSlot;
    cout << "Enter the fixed time slot for each process: ";
    cin >> timeSlot;

    RoundRobinScheduler scheduler(timeSlot);

    int choice, processID, execTime;

    while (true) {
        choice = scheduler.getMenu();

        switch(choice) {
            case 1: // Insert Process
                cout << "Enter Process ID: ";
                cin >> processID;
                cout << "Enter Execution Time: ";
                cin >> execTime;
                scheduler.insertProcess(processID, execTime);
                scheduler.display();
                break;

            case 2: // Execute Process
                scheduler.execute();
                scheduler.display();
                break;

            case 3: // Exit
                cout << "Exiting program...\n";
                exit(0);

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to display menu
int RoundRobinScheduler::getMenu() {
    int choice;
    cout << "\n----- Round Robin Scheduling -----\n";
    cout << "1. Insert Process\n";
    cout << "2. Execute\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Check if the list is empty
bool RoundRobinScheduler::isEmpty() {
    return head == nullptr;
}

// Function to insert a process into the circular linked list
void RoundRobinScheduler::insertProcess(int processID, int execTime) {
    struct Process* newProcess = new Process();
    newProcess->processID = processID;
    newProcess->remainingTime = execTime;
    
    if (head == nullptr) {
        newProcess->next = newProcess;  // Circular link to itself
        head = newProcess;
    } else {
        struct Process* temp = head;
        while (temp->next != head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newProcess;
        newProcess->next = head; // Link new process to the head
    }
}

// Function to execute the process
void RoundRobinScheduler::execute() {
    if (isEmpty()) {
        cout << "No processes to execute.\n";
        return;
    }

    struct Process* current = head;
    
    // Remove the process from the beginning (FIFO)
    head = current->next;

    // Subtract the time slice from the remaining time
    current->remainingTime -= timeSlice;
    cout << "Executing Process ID: " << current->processID << ", Remaining Time: " << current->remainingTime << endl;

    // If the process is not completed, reinsert it at the end of the queue
    if (current->remainingTime > 0) {
        insertProcess(current->processID, current->remainingTime);
        cout << "Process ID: " << current->processID << " has remaining time. Reinserted into the queue.\n";
    } else {
        cout << "Process ID: " << current->processID << " has completed.\n";
    }

    // Delete the current process (which is completed or moved)
    delete current;
}

// Function to display the list of processes and their remaining time
void RoundRobinScheduler::display() {
    if (isEmpty()) {
        cout << "No processes in the queue.\n";
        return;
    }

    struct Process* temp = head;
    cout << "Processes in the queue: \n";
    
    // Traverse and display all processes in the circular list
    do {
        cout << "Process ID: " << temp->processID << ", Remaining Time: " << temp->remainingTime << endl;
        temp = temp->next;
    } while (temp != head);
}
