#include <iostream> // To use cout
#include <random>   // To use pseudo-random numbers
#include <vector>   // To use STL vectors
#include <chrono>   // To measure durations

using namespace std;


int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << "\t" << "N  T [with N the number of elements in the arrays, and T the number of threads]" << endl;
        return EXIT_FAILURE;
    }

    int N = atoi(argv[1]);
    int T = atoi(argv[2]);

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_real_distribution<double> uniform_distribution;

    cout << "Run allocation" << endl;
    auto start = chrono::high_resolution_clock::now();
    vector<double> a(N);
    vector<double> b(N);
    vector<double> c(N);
    vector<double> d(N);
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration<double>(end - start).count();
    cout << "Allocation took " << time_taken << " seconds" << endl << endl;

    cout << "Run initialisation" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        a[i] = uniform_distribution(generator);
        b[i] = uniform_distribution(generator);
    }
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration<double>(end - start).count();
    cout << "Initialisation took " << time_taken << " seconds" << endl << endl;

    cout << "Run sums" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    c[i] = a[i] + b[i];
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration<double>(end - start).count();
    cout << "Sums took " << time_taken << " seconds" << endl << endl;

    cout << "Run products" << endl;
    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    d[i] = a[i] * b[i];
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration<double>(end - start).count();
    cout << "Products took " << time_taken << " seconds" << endl << endl;

    // Print the result in the terminal
    for (int i = 0; i < N; i++)
    {
        cout << c[i] << " = " << a[i] << " + " << b[i] << endl;
        cout << d[i] << " = " << a[i] << " * " << b[i] << endl << endl;
    }

    return 0;
}