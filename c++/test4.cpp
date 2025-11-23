#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Contact {
    string name;
    string phone;
    
    Contact(const string& n, const string& p) : name(n), phone(p) {}
};


class PhoneBook {
private:
    vector<Contact> contacts;

public:    void addContact(const string& name, const string& phone) {
        contacts.push_back(Contact(name, phone));
        cout << "联系人添加成功！" << endl;
    }


    void findNameByPhone(const string& phone) {
        bool found = false;
        cout << "查找结果：" << endl;
        
        for (const auto& contact : contacts) {
            if (contact.phone == phone) {
                cout << "姓名: " << contact.name << ", 电话: " << contact.phone << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "未找到电话号码为 " << phone << " 的联系人" << endl;
        }
    }

    void findPhoneByName(const string& name) {
        bool found = false;
        cout << "查找结果：" << endl;
        
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "姓名: " << contact.name << ", 电话: " << contact.phone << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "未找到姓名为 " << name << " 的联系人" << endl;
        }
    }


    void searchByPhonePrefix(const string& prefix) {
        bool found = false;
        cout << "以 " << prefix << " 开头的电话号码：" << endl;
        
        for (const auto& contact : contacts) {

            if (contact.phone.find(prefix) == 0) {
                cout << "姓名: " << contact.name << ", 电话: " << contact.phone << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "未找到以 " << prefix << " 开头的电话号码" << endl;
        }
    }

    void searchByNameContains(const string& keyword) {
        bool found = false;
        cout << "姓名中包含 \"" << keyword << "\" 的联系人：" << endl;
        
        for (const auto& contact : contacts) {
            if (contact.name.find(keyword) != string::npos) {
                cout << "姓名: " << contact.name << ", 电话: " << contact.phone << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "未找到姓名中包含 \"" << keyword << "\" 的联系人" << endl;
        }
    }
    void displayAll() {
        if (contacts.empty()) {
            cout << "电话簿为空" << endl;
            return;
        }
        
        cout << "所有联系人：" << endl;
        for (size_t i = 0; i < contacts.size(); i++) {
            cout << i + 1 << ". 姓名: " << contacts[i].name 
                 << ", 电话: " << contacts[i].phone << endl;
        }
    }
};

// 显示菜单
void displayMenu() {
    cout << "1. 添加联系人" << endl;
    cout << "2. 通过电话查找姓名" << endl;
    cout << "3. 通过姓名查找电话" << endl;
    cout << "4. 电话前缀搜索" << endl;
    cout << "5. 姓名模糊搜索" << endl;
    cout << "6. 显示所有联系人" << endl;
    cout << "7. 退出" << endl;
    cout << "请选择操作 (1-7): ";
}

int main() {
    PhoneBook phoneBook;
    int choice;
    
    // 添加一些示例数据
    phoneBook.addContact("张三", "13800138000");
    phoneBook.addContact("李四", "13900139000");
    phoneBook.addContact("王五", "13800138111");
    phoneBook.addContact("张伟", "13900139222");
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区
        
        string name, phone, prefix, keyword;
        
        switch (choice) {
            case 1:
                cout << "请输入姓名: ";
                getline(cin, name);
                cout << "请输入电话号码: ";
                getline(cin, phone);
                phoneBook.addContact(name, phone);
                break;
                
            case 2:
                cout << "请输入电话号码: ";
                getline(cin, phone);
                phoneBook.findNameByPhone(phone);
                break;
                
            case 3:
                cout << "请输入姓名: ";
                getline(cin, name);
                phoneBook.findPhoneByName(name);
                break;
                
            case 4:
                cout << "请输入电话前缀: ";
                getline(cin, prefix);
                phoneBook.searchByPhonePrefix(prefix);
                break;
                
            case 5:
                cout << "请输入姓名关键词: ";
                getline(cin, keyword);
                phoneBook.searchByNameContains(keyword);
                break;
                
            case 6:
                phoneBook.displayAll();
                break;
                
            case 7:
                cout << "感谢使用电话号码簿检索系统！" << endl;
                break;
                
            default:
                cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice != 7);
    
    return 0;
}