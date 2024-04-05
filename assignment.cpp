#include <iostream>
#include <vector>

using namespace std;

// Contact class
class Contact {
public:
    string id;
    string name;
    string address;

    Contact(const string& _id, const string& _name const string& _address) : id(_id), name(_name), address(_address) {}
};

// Deal class
class Deal {
public:
    string id;
    string contactId;
    int year;

    Deal(const string& _id, const string& _contactId, int _year) : id(_id), contactId(_contactId), year(_year) {}
};

// Function to sync deals with contacts
void syncDealsWithContacts(const vector<Contact>& contacts, const vector<Deal>& deals) {
    for (const auto& deal : deals) {
        for (const auto& contact : contacts) {
            if (deal.year > 2021 && deal.contactId == contact.id) {
                cout << "Syncing deal " << deal.id << " with contact " << contact.name << endl;
                break;
            }
        }
    }
}

int main() {
    // Sample contacts data
    vector<Contact> contacts = {
        {"1", "John", "Mumbai"},
        {"2", "Alice", "Delhi"}
    };

    // Sample deals data
    vector<Deal> deals = {
        {"101", "1", 2023},
        {"101", "1", 2022},
        {"102", "2", 2022}
    };

    // Sync deals with contacts
    syncDealsWithContacts(contacts, deals);

    return 0;
}