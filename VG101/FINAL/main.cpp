// g++ -std=c++11
// Jigang's note: please change the above to your compiler if needed

// Jigang's note: add additional header files if needed
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
 
using namespace std;

///////////////////////////////
// Jigang's note: please fill in the codes in each
// function below according to instructions

// problem 1 - please fill in the codes
void P1()
{
    string s;
    string final;
    getline(cin,s);
    final="Hello "+s+"!";
    cout<<final<<endl;
}

// problem 2 - please fill in the codes
int P2(int N, int k, int m)
{// feel free to change the following codes in the function
    int num=N/k;
    int S = 0;
    for (int i=1;i<=num;++i)
    {
        S+=pow(i*k,m);
    }
    return S;
}

// problem 3 - please fill in the codes
// you need to add necessary member variables and fill in the provided member functions
class P3
{
public:
    double a;
    double b;
    double c;
    P3() // constructor with no input arguments. By default, the coefficients (a, b, c) = (1, 0, 0);
    {
        a=1;b=0;c=0;
    }
    P3(double aa, double bb, double cc) // constructor with 3 numbers to initialize the coefficients (a, b, c)
    {
        a=aa;
        b=bb;
        c=cc;
    }
    // get solutions of the quadratic function in x and y, return value is the number of solutions
    // if number of solutions = 0, set x = y = 0;
    // if number of solutions = 1, both values of x and y are the solution
    // if number of solutions = 2, x and y are the two solutions where x < y
    int GetSolutions(double &x, double &y)
    {// feel free to change the following codes in the function
        double delta=0;
        int num = 0; // number of solutions
        delta=pow(b,2)-4*a*c;
        // cout<<"delta="<<delta<<endl;
        if (delta<0)
        {
            num=0;
            x=0;
            y=0;
        }
        else if (delta==0)
        {
            num=1;
            x=(-b+sqrt(delta))/(2*a);
            y=(-b+sqrt(delta))/(2*a);
        }
        else if (delta>0)
        {
            num=2;
            x=(-b+sqrt(delta))/(2*a);
            y=(-b-sqrt(delta))/(2*a);
        }
        return num;
    }
};

// problem 4 - please fill in the codes
void P4()
{
    ifstream in("p4.txt");
    ostringstream result;
    vector<string> vec;
    string str;
    while (getline(in,str))
    {
        istringstream input(str);
        while (input>>str)
        {
            vec.push_back(str);
        }
        sort(vec.begin(),vec.end());
        for (auto &v:vec) result<<v<<" ";
        result<<endl;
        vec.clear();
    }
    cout<<result.str();
}
// problem 5 - please fill in the codes
void P5()
{
    ifstream in("p5.txt");
    vector<string> vec;
    vector<int> flag;
    string str;
    while (getline(in,str))
    {
        istringstream input(str);
        while (input>>str) vec.push_back(str+" ");
    }
    reverse(vec.begin(),vec.end());
    vector<unsigned int> length;
    for (auto &v:vec) length.push_back(v.size());

    ostringstream result;

    int cnt=0,cup=0,sz=0;
    for (auto &v:length){
        cnt++; sz+=v;
        cout<<cnt<<" "<<cup<<" "<<sz<<endl;
        if (cup<sz){
            flag.push_back(cnt);
            cup=sz; sz=0;
        }
    }
    if (cup>=sz&&sz!=0) flag.pop_back();
    reverse(vec.begin(),vec.end());
    reverse(flag.begin(),flag.end());
    cnt=vec.size();
    vector<int>::iterator nw=flag.begin();
    for (auto &v:flag) cout<<v<<endl;
    for (auto &v:vec){
        result<<v; 
        cnt--;
        if (cnt==*nw){
            result<<endl;
            nw++;
        }
    }

    string reverse;
    reverse=result.str();
    cout<<reverse;
    
}

////////////////////////////////////////////////
// Jigang's note: YOU DON'T NEED TO CHANGE THE FOLLOWING CODES
// to test your program, run the file and input the problem number
// as instructed
int main(int argc, char** argv)
{
    int n = 0; // problem number
    if (argc == 1)
    {
        cout << "Input problem number (1-5): ";
        cin >> n;
        cin.ignore(); // ignore the rest of stdin buffer
    }
    else if (argc == 2)
    {
        if (argv[1][1] != '\0') {cout << "Invalid argument!" << endl; return -1;}
        switch(argv[1][0])
        {
            case '1': n = 1; break;
            case '2': n = 2; break;
            case '3': n = 3; break;
            case '4': n = 4; break;
            case '5': n = 5; break;
            default: cout << "Invalid argument!" << endl; return -1;
        }
    }
    cout << "Run problem " << n << endl;
    if (n == 1) P1();
    else if (n == 2)
    {
        // testing codes
        cout << "P2(10, 3, 2) = " << P2(10, 3, 2) << endl;
        cout << "P2(100, 4, 3) = " << P2(100, 4, 3) << endl;
        cout << "P2(50, 6, 4) = " << P2(50, 6, 4) << endl;
        cout << "P2(123, 9, 1) = " << P2(123, 9, 1) << endl;
        cout << "P2(1000, 11, 2) = " << P2(1000, 11, 2) << endl;
    }
    else if (n == 3)
    {
        // testing codes
        P3 eq1, eq2(1, 2, 1), eq3(1, 0, -2), eq4(1, 1, 1);
        double x, y;
        int n;
        n = eq1.GetSolutions(x, y);
        cout << "Equation 1: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
        n = eq2.GetSolutions(x, y);
        cout << "Equation 2: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
        n = eq3.GetSolutions(x, y);
        cout << "Equation 3: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
        n = eq4.GetSolutions(x, y);
        cout << "Equation 4: " << n << " solutions, " << "x = " << x << ", y = " << y << endl;
    }
    else if (n == 4) P4();
    else if (n == 5) P5();
    return 0;
}
