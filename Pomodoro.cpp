#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void startTimer(int minutes) {
    auto start = chrono::steady_clock::now();
    auto end = start + chrono::minutes(minutes);

    while (chrono::steady_clock::now() < end) {
        auto remainingTime = chrono::duration_cast<chrono::seconds>(end - chrono::steady_clock::now()).count();
        cout << "\rTime remaining: " << remainingTime / 60 << " minutes and " << remainingTime % 60 << " seconds" << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "\n";
}

int main() {
    cout << "Pomodoro Timer Started!\n";
    int workSessions = 0;

    while (true) {
        cout << "Work for 25 minutes.\n";
        startTimer(25);
        workSessions++;

        if (workSessions % 3 == 0) {
            cout << "Take a 15-minute break.\n";
            startTimer(15);
        }
        else {
            cout << "Take a 5-minute break.\n";
            startTimer(5);
        }
    }

    return 0;
}
