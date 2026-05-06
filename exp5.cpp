#include<iostream>
#include<fstream>
using namespace std;

struct EMP {
    int id;
    char name[20];
    char desig[20];
    float salary;
};

class File {
    EMP e;

public:

    void add() {
        ofstream out("emp.dat", ios::binary | ios::app);

        cout << "Enter ID Name Designation Salary:\n";
        cin >> e.id >> e.name >> e.desig >> e.salary;

        out.write((char*)&e, sizeof(e));
        out.close();
    }

    void display() {
        ifstream in("emp.dat", ios::binary);

        while(in.read((char*)&e, sizeof(e))) {
            cout << e.id << " " << e.name << " "
                 << e.desig << " " << e.salary << endl;
        }
        in.close();
    }

    void search(char name[]) {
        ifstream in("emp.dat", ios::binary);
        bool found = false;

        while(in.read((char*)&e, sizeof(e))) {
            if(strcmp(e.name, name) == 0) {
                cout << "Found: " << e.id << " " << e.name << endl;
                found = true;
            }
        }

        if(!found) cout << "Not found\n";
        in.close();
    }

    void update(char name[]) {
        fstream file("emp.dat", ios::binary | ios::in | ios::out);

        while(file.read((char*)&e, sizeof(e))) {
            if(strcmp(e.name, name) == 0) {
                cout << "Enter new data:\n";
                cin >> e.id >> e.name >> e.desig >> e.salary;

                file.seekp(-sizeof(e), ios::cur);
                file.write((char*)&e, sizeof(e));
                return;
            }
        }

        cout << "Not found\n";
        file.close();
    }

    void removeRec(char name[]) {
        ifstream in("emp.dat", ios::binary);
        ofstream out("temp.dat", ios::binary);

        while(in.read((char*)&e, sizeof(e))) {
            if(strcmp(e.name, name) != 0) {
                out.write((char*)&e, sizeof(e));
            }
        }

        in.close();
        out.close();

        remove("emp.dat");
        rename("temp.dat", "emp.dat");
    }
};

int main() {
    File f;
    int ch;
    char name[20];

    do {
        cout << "\n1.Add 2.Display 3.Search 4.Update 5.Delete 6.Exit\n";
        cin >> ch;

        switch(ch) {
            case 1: f.add(); break;
            case 2: f.display(); break;
            case 3:
                cout << "Enter name: ";
                cin >> name;
                f.search(name);
                break;
            case 4:
                cout << "Enter name: ";
                cin >> name;
                f.update(name);
                break;
            case 5:
                cout << "Enter name: ";
                cin >> name;
                f.removeRec(name);
                break;
        }

    } while(ch != 6);

    return 0;
}