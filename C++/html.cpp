#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int a;
    // std::string response = "Hello from C++";
    // cout << "Content-type: text/plain\n\n";pppnn
    // cout << response;
    cout << "Content-Type: text/html\n\n";
    cout << "<html><head><style>";
    cout << "body { background-color: #f0f0f0; }";
    cout << "h1 { color: #333; }";
    cout << "</style></head><body>";
    cout << "<h1>Hello, World!</h1>";
    cout << "<h1>My name is Syed Huzaifa Nazim and I'll be the Project Incharge of OOP in Cpp</h1>";
    cin >> a;
    cout << "<script>";
    cout << "document.addEventListener('DOMContentLoaded', function() {";
    cout << "    alert('Hello, World!');";
    cout << "});";
    cout << "</script></body></html>";
    return 0;
}