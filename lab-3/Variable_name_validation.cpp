#include <bits/stdc++.h>
using namespace std;

bool isValidIdentifier(string variable) {
    if (variable == "alignas" || variable == "alignof" || variable == "and" || variable == "and_eq" || variable == "asm" || variable == "atomic_cancel" ||
        variable == "atomic_commit" || variable == "atomic_noexcept" || variable == "auto" || variable == "bitand" || variable == "bitor" || variable == "bool" ||
        variable == "break" || variable == "case" || variable == "catch" || variable == "char" || variable == "char8_t" || variable == "char16_t" ||
        variable == "char32_t" || variable == "class" || variable == "compl" || variable == "concept" || variable == "const" || variable == "consteval" ||
        variable == "constexpr" || variable == "constinit" || variable == "const_cast" || variable == "continue" || variable == "co_await" || variable == "co_return" ||
        variable == "co_yield" || variable == "decltype" || variable == "default" || variable == "delete" || variable == "do" || variable == "double" || variable == "dynamic_cast" ||
        variable == "else" || variable == "enum" || variable == "explicit" || variable == "export" || variable == "extern" || variable == "false" || variable == "float" ||
        variable == "for" || variable == "friend" || variable == "goto" || variable == "if" || variable == "inline" || variable == "int" || variable == "long" ||
        variable == "mutable" || variable == "namespace" || variable == "new" || variable == "noexcept" || variable == "not" || variable == "not_eq" || variable == "nullptr" ||
        variable == "operator" || variable == "or" || variable == "or_eq" || variable == "private" || variable == "protected" || variable == "public" || variable == "register" ||
        variable == "reinterpret_cast" || variable == "requires" || variable == "return" || variable == "short" || variable == "signed" || variable == "sizeof" || variable == "static" ||
        variable == "static_assert" || variable == "static_cast" || variable == "struct" || variable == "switch" || variable == "synchronized" || variable == "template" || variable == "this" ||
        variable == "thread_local" || variable == "throw" || variable == "true" || variable == "try" || variable == "typedef" || variable == "typeid" || variable == "typename" ||
        variable == "union" || variable == "unsigned" || variable == "using" || variable == "virtual" || variable == "void" || variable == "volatile" || variable == "wchar_t" ||
        variable == "while" || variable == "xor" || variable == "xor_eq") {

        cout << "Invalid: Variable name can't be the same as a keyword name\n";
        return false;
    }
    if (variable.empty()) {
        cout << "Invalid: Variable name is empty.\n";
        return false;
    }

    if (!(variable[0] == '_' || (variable[0] >= 'a' && variable[0] <= 'z') ||
          (variable[0] >= 'A' && variable[0] <= 'Z'))) {
        cout << "Invalid: Variable name starts with '" << variable[0] << "' which is invalid.\n";
        return false;
    }

    for (int i = 1; i < variable.size(); ++i) {
        if (!(variable[i] == '_' || (variable[i] >= 'a' && variable[i] <= 'z') ||
              (variable[i] >= 'A' && variable[i] <= 'Z') ||
              (variable[i] >= '0' && variable[i] <= '9'))) {
            if (variable[i] == ' ') {
                cout << "Invalid: Space should not be included in the variable name.\n";
                return false;
            }
            cout << "Invalid: '" << variable[i] << "' should not be included in the variable name.\n";
            return false;
        }
    }

    cout << "Variable name is valid.\n";
    return true;
}

int main() {
    string var;

    cout << "Enter a variable name: ";
    getline(cin, var);

    isValidIdentifier(var);

    return 0;
}
