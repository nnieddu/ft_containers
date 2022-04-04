/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:43:42 by ninieddu          #+#    #+#             */
/*   Updated: 2022/04/04 17:35:31 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stack>
#include <map>

#include "containers/ft_vector.hpp"
#include "containers/ft_stack.hpp"
#include "containers/ft_map.hpp"

#define DUMPSTR_WNAME(os, name, a) \
    do { (os) << (name) << " = " << (a) << std::endl; } while(false)
	
#define DUMPSTR_WNAME_NO_STDENDL(os, name, a) \
    do { (os) << (name) << " = " << "[" << (a) << "]"; } while(false)
	
#define DUMPSTR(os, a) DUMPSTR_WNAME((os), #a, (a))
#define DUMP(a)        DUMPSTR_WNAME(std::cout, #a, (a))
#define DUMPN(a)        DUMPSTR_WNAME_NO_STDENDL(std::cout, #a, (a))

#define COUT_I(os, name, i) \
    do { (os) << " " << (name) << " = " << (i++) << std::endl; } while(false)
	
#define COUNT(i)       COUT_I(std::cout, #i, (i))



#define MAX_TEST 10000

void	printOk() {
	std::cout << "\033[0;32m" << "V" << "\033[0;37m";
}

void	printError(std::string message) {
	std::cout << "\033[0;31m" << message << "\033[0;37m" << std::endl;
}

void	printvector(ft::vector<std::string> vector) 
{
	for (unsigned long i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}




# define SANDBOX(x) do {             \
    testSegvPid = fork();            \
    if (testSegvPid == -1) abort();  \
    if (testSegvPid == 0) {          \
        do { (void)(x); } while(0);  \
        exit(EXIT_SUCCESS);          \
    }                                \
    wait(&testSegvPid);              \
} while(0)

# define ASSERT(x) do {                                                         \
    SANDBOX(x);                                                                 \
    if (!WIFEXITED(testSegvPid)) log("[FAIL SEGV  ] ", __FILE__, __LINE__, #x); \
    else if (!(x))               log("[FAIL ASSERT] ", __FILE__, __LINE__, #x); \
    else                         log("[PASS       ] ", __FILE__, __LINE__, #x); \
} while(0)

# define TEST_SEGV(x) do {                                                      \
    SANDBOX(x);                                                                 \
    if (!WIFEXITED(testSegvPid)) log("[FAIL SEGV  ] ", __FILE__, __LINE__, #x); \
    else                         log("[PASS       ] ", __FILE__, __LINE__, #x); \
} while(0)


# include <iostream>
# include <string>
# include <algorithm>

# include <cstdlib>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

static pid_t testSegvPid;
extern std::string testName;
extern std::string testContainer;

std::string testName = "";
std::string testContainer = "";

void log(const std::string& prefix,
         const std::string& filename,
         int lineNum,
         const std::string& code)
{
    std::cout << prefix << "{"
              << testContainer << "} {"
              << ::testName << "} "
              << filename << ':'
              << lineNum
              << " (" << code << ")"
              << std::endl;
}


int main ()
{
    testName = "vector.operator=";

    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::vector<int>                 v1_duplicated(arr1, arr1 + 5);
    ft::vector<std::string>         v2_duplicated(arr2, arr2 + 3);
    ft::vector<float>               v3_duplicated(6, 42.0f);
    ft::vector< ft::vector<char*> > v4_duplicated;

    ft::vector<int> v1;
    v1 = v1_duplicated;
    ASSERT(v1.empty() == v1_duplicated.empty());
    ASSERT(v1.size() == v1_duplicated.size());
    ASSERT(v1.capacity() == v1_duplicated.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == v1_duplicated[i]);
    v1[0] = 0;
    ASSERT(v1[0] == 0);
    ASSERT(v1_duplicated[0] == 1);

    ft::vector<std::string> v2(10, "zzz");
    v2 = v2_duplicated;
    ASSERT(v2.empty() == v2_duplicated.empty());
    ASSERT(v2.size() == v2_duplicated.size());
    // ASSERT(v2.capacity() == v2_duplicated.capacity()); //////////////////////////////
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == v2_duplicated[i]);
    v2[0] = "aaa";
    ASSERT(v2[0] == "aaa");
    ASSERT(v2_duplicated[0] == "bonjour");
    v2[1] = "bbb";
    ASSERT(v2[1] == "bbb");
    ASSERT(v2_duplicated[1] == "je");
    v2[2] = "ccc";
    ASSERT(v2[2] == "ccc");
    ASSERT(v2_duplicated[2] == "suis");

    ft::vector<float> v3(v3_duplicated);
    v3 = v3_duplicated;
    ASSERT(v3.empty() == v3_duplicated.empty());
    ASSERT(v3.size() == v3_duplicated.size());
    ASSERT(v3.capacity() == v3_duplicated.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == v3_duplicated[i]);
    v3[5] = 19.19f;
    ASSERT(v3[5] == 19.19f);
    ASSERT(v3_duplicated[0] == 42.0f);

    ft::vector< ft::vector<char*> > v4(2, ft::vector<char*>(2, NULL));
    v4 = v4_duplicated;
    ASSERT(v4.empty() == v4_duplicated.empty());
    ASSERT(v4.size() == v4_duplicated.size());
    // ASSERT(v4.capacity() == v4_duplicated.capacity()); //////////////////////////////
}