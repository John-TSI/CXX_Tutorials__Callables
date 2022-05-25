#include<iostream>
#include<string>
#include<concepts>


int main()
{
    int x = 4;
    const int y = 7;

    //auto lamb1 = [x]() {x++;};  // captures x by value, capt by ref to modify
    auto lamb2 = [&x]() {x++; };  // fixes above issue by capturing reference to x
    //auto lamb3 = [&y]() {y++;};  // captures ref to const variable y, cannot modify y
    auto lamb4 = [y]() {};  // captures const variable y by value, doesn't modify y


    //auto gen_lam = [](auto T1, auto T2) { return T1 * T2; };  // arguments must have arithmetic type
    //auto gen_lam = [](std::integral auto T1, std::integral auto T2) { return T1 * T2; };  // fixes above issue, constrains lambda arguments to be of integral type 

    //auto ans1 = gen_lam(3, 4);  // no issues
    //auto ans2 = gen_lam('c', 'd');  // will cast char types to int
    //auto ans3 = gen_lam("Hello", "World");  // cannot multiply strings
    using namespace std::string_literals;
    //auto ans3 = gen_lam("Hello"s, "World"s);  // cannot multiply string literals

    // --- custom lambda ---
    std::string str = "string1", str2 = "string2";
    auto stringSwapper = [&str, &str2]() { std::string tmp = str; str = str2; str2 = tmp; };
    stringSwapper();
    std::cout << "str = " << str << ", str2 = " << str2 << "\n";

    return 0;
}
