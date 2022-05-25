#include<iostream>
#include <functional>
#include <numbers>
#include<string>


// --- required callables to support ---
double get_circle_area(int radius) {  // one
	return std::numbers::pi * static_cast<double>(radius * radius);
}

struct triangle {  // two
	double get_area(int width, int height) { return static_cast<double>(width * height) / 2.0; }
};

struct stringer {  // three
	std::string operator()(const std::string& str1, const std::string& str2) {
		return str1 + '_' + str2;
	}
};

auto math_lambda = [](int first, int second, int multiplier) {return (first + second) * multiplier; };  // four


// --- the RunAll() function ---
template <typename Callable, typename ... Args>
auto RunAll(Callable&& callable, Args&& ... args)
{
    return std::invoke(callable, args...);
}



int main()
{   system("cls");

    // --- callable one ---
    std::cout << RunAll(get_circle_area, 12) << "\n";


    // --- callable two ---

    //auto tri_mem_fn = std::mem_fn(&triangle::get_area);
    //triangle my_tri;
    //std::cout << RunAll(tri_mem_fn, my_tri, 5, 8) << "\n";

    std::cout << RunAll(std::mem_fn(&triangle::get_area), triangle(), 5, 8) << "\n";


    // --- callable three ---

    /* auto op = std::mem_fn(&stringer::operator());
    stringer str;
    std::cout << RunAll(op, str, "FOO", "BAR") << "\n"; */
    
    //std::cout << RunAll(std::mem_fn(&stringer::operator()), stringer(), "FOO", "BAR") << "\n"; 
    std::cout << RunAll(stringer(), "FOO", "BAR") << "\n";


    // --- callable four ---
    std::cout << RunAll(math_lambda, 4,6,8) << "\n";

    return 0;
}