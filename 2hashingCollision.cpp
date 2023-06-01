/*Implement all the functions of a dictionary (ADT) using hashing and handle collisions 
using chaining with / without replacement. 
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys 
must be unique 
Standard Operations: Insert(key, value), Find(key), Delete(key) */

#include <iostream>
#include <cstring>
using namespace std;
class Dictionary {
 struct obj {
 long key;
 char clnt_name[10];
 };
 obj h[10];
public:
 Dictionary();
 void add_record();
 void show();
 int search(long);
 void delete_rec(long);
};
Dictionary::Dictionary() {
 for (int i = 0; i < 10; i++) {
 h[i].key = -1;
 strcpy(h[i].clnt_name, "NULL");
 }
}
void Dictionary::delete_rec(long k) {
 int index = search(k);
 if (index == -1) {
 cout << "\n\tKey not found";
 } else {
 h[index].key = -1;
 strcpy(h[index].clnt_name, "NULL");
 cout << "\n\tKey is deleted";
 }
}

int Dictionary::search(long k) {
 for (int i = 0; i < 10; i++) {
 if (h[i].key == k) {
 cout << "\n\t" << h[i].key << " is found at " << i << " location with client " << 
h[i].clnt_name;
 return i;
 }
 }
 return -1;
}
void Dictionary::show() {
 cout << "\n\t\tKey\t\tClient Name";
 for (int i = 0; i < 10; i++) {
 cout << "\n\th[" << i << "]\t" << h[i].key << "\t\t" << h[i].clnt_name;
 }
}
void Dictionary::add_record() {
 char ans, n[10], ntemp[10];
 long k, temp;
 int hi, cnt = 0, flag = 0, i;
 do {
 if (cnt >= 10) {
 cout << "\n\tHash table is full";
 break;
 }
 cout << "\n\tEnter a telephone number: ";
 cin >> k;
 cout << "\n\tEnter a client name: ";
 cin >> n;
 hi = k % 10;
 if (h[hi].key == -1) {
 h[hi].key = k;
 strcpy(h[hi].clnt_name, n);
 } else {
 if (h[hi].key % 10 != hi) {
 temp = h[hi].key;
 strcpy(ntemp, h[hi].clnt_name);
 h[hi].key = k;
 strcpy(h[hi].clnt_name, n);
 for (i = hi + 1; i < 10; i++) {
 if (h[i].key == -1) {
 h[i].key = temp;
 strcpy(h[i].clnt_name, ntemp);
 flag = 1;
 break;
 }
}
 for (i = 0; i < hi && flag == 0; i++) {
 if (h[i].key == -1) {
 h[i].key = temp;
 strcpy(h[i].clnt_name, ntemp);
 break;
 }
 }
 } else {
 for (i = hi + 1; i < 10; i++) {
 if (h[i].key == -1) {
 h[i].key = k;
 strcpy(h[i].clnt_name, n);
 flag = 1;
 break;
 }
 }
 for (i = 0; i <hi && flag == 0; i++)
 {
 if (h[i].key == -1)
 {
 h[i].key = k;
 strcpy(h[i].clnt_name, n);
 break;
 }
 }
 }
 }
 flag = 0;
 cnt++;
 cout << "\n\t......Do You Want to Insert more Keys? (y/n): ";
 cin >> ans;
 } while (ans == 'y' || ans == 'Y');
}
int main()
{
 Dictionary d;
 int choice;
 long key;
 do
 {
 cout << "\n\n----- Dictionary Menu -----";
 cout << "\n1. Add Record";
 cout << "\n2. Delete Record";
 cout << "\n3. Search Record";
cout << "\n4. Show Dictionary";
 cout << "\n5. Exit";
 cout << "\nEnter your choice: ";
 cin >> choice;
 switch (choice)
 {
 case 1:
 d.add_record();
 break;
 case 2:
 cout << "\nEnter the key to delete: ";
 cin >> key;
 d.delete_rec(key);
 break;
 case 3:
 cout << "\nEnter the key to search: ";
 cin >> key;
 d.search(key);
 break;
 case 4:
 d.show();
 break;
 case 5:
 cout << "\nExiting program...";
 break;
 default:
 cout << "\nInvalid choice! Please try again.";
 }
 } while (choice != 5);
 return 0;
}
