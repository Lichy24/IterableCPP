
#include <iostream>
#include <string>
using namespace std;

#include "powerset.hpp"
#include "product.hpp"
#include "zip.hpp"
#include "chain.hpp"
#include "range.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
		std::string AnsEmpty = "";
		std::string range1, range2, range3,range4,range5,range6;
		std::string rangeAns1 = "5678", rangeAns2 = "5.1 6.1 7.1 8.1 ", rangeAns3 = "a b c d ";
		std::string chain1, chain2, chain3,chain4,chain5,chain6;
		std::string chainAns1 = "hello", chainAns2 = "123567", chainAns3 = "abcdhello", chainAns4 = "1,a 2,b 3,c 1,a 1,b 1,c 2,a 2,b 2,c 3,a 3,b 3,c ", chainAns5 = "123456";
		std::string zip1, zip2,zip3,zip4,zip5;
		std::string zipAns1 = "1,h 2,e 3,l 4,l 5,o ", zipAns2 = "1,x,a,6 2,y,b,7 3,z,c,8 ", zipAns3= "1,4,k 2,5,k 3,6,k a,4,o d,5,o c,6,o ",zipAns4= "{},{} {1},{4} {2},{5} {1,2},{4,5} ";
		std::string product1,product2,product3;
		std::string productAns1 = "1,h 1,e 1,l 1,l 1,o 2,h 2,e 2,l 2,l 2,o 3,h 3,e 3,l 3,l 3,o ",productAns2= "1,a,a,1 1,a,a,2 1,a,a,3 1,a,h,1 1,a,h,2 1,a,h,3 2,a,a,1 2,a,a,2 2,a,a,3 2,a,h,1 2,a,h,2 2,a,h,3 3,a,a,1 3,a,a,2 3,a,a,3 3,a,h,1 3,a,h,2 3,a,h,3 ";
		std::string powerset1,powerset2,powerset3,powerset4;
		std::string powersetAns1 = "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}",powersetAns2= "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}",powersetAns3= "{} {{}} {{1}} {{},{1}} {{2}} {{},{2}} {{1},{2}} {{},{1},{2}} {{1,2}} {{},{1,2}} {{1},{1,2}} {{},{1},{1,2}} {{2},{1,2}} {{},{2},{1,2}} {{1},{2},{1,2}} {{},{1},{2},{1,2}} ",EmptyPowersetAns = "{}";
		std::stringstream ss;

		for (int i : range(5, 9))
			ss << i;
		range1 = ss.str();
		ss.str(std::string());

		for (double i : range(5.1, 9.1))
			ss << i << " ";
		range2 = ss.str();
		ss.str(std::string());

		for (char i : range('a', 'e'))
			ss << i << " ";
		range3 = ss.str();
		ss.str(std::string());

		for (char i : range('e', 'e'))
			ss << i;
		range4 = ss.str();
		ss.str(std::string());

		for (double i : range(9.1, 9.1))
			ss << i;
		range5 = ss.str();
		ss.str(std::string());

		for (int i : range(9, 9))
			ss << i;
		range6 = ss.str();
		ss.str(std::string());

		testcase.setname("Range test")
			.CHECK_EQUAL(range1,rangeAns1)
			.CHECK_EQUAL(range2,rangeAns2)
			.CHECK_EQUAL(range3,rangeAns3)
			.CHECK_EQUAL(range4,AnsEmpty)
			.CHECK_EQUAL(range5,AnsEmpty)
			.CHECK_EQUAL(range6,AnsEmpty);
		
		for (char i : string("hello"))
			ss << i;
		chain1 = ss.str();
		ss.str(std::string());
		
		for (int i : chain(range(1, 4), range(5, 8)))
			ss << i;
		chain2 = ss.str();
		ss.str(std::string());

		for (char i : chain(range('a', 'e'), string("hello")))
			ss << i;
		chain3 = ss.str();
		ss.str(std::string());
		
		for (auto i : chain(zip(range(1,4),range('a','d')), product(range(1,4),range('a','d'))))
			ss << i << " ";
		chain4 = ss.str();
		ss.str(std::string());
		
		for (auto i : chain(chain(range(1, 3), range(3, 5)), chain(range(5, 6), range(6, 7))))
			ss << i;
		chain5 = ss.str();
		ss.str(std::string());
		
		for (auto i : chain(range(1,1), range(1, 1)))
			ss << i;
		chain6 = ss.str();
		ss.str(std::string());
		testcase.setname("Chain test")
			.CHECK_EQUAL(chain1, chainAns1)
			.CHECK_EQUAL(chain2, chainAns2)
			.CHECK_EQUAL(chain3, chainAns3)
			.CHECK_EQUAL(chain4, chainAns4)
			.CHECK_EQUAL(chain5, chainAns5)
			.CHECK_EQUAL(chain6, AnsEmpty);

		for (auto pair : zip(range(1, 6), string("hello")))
			ss << pair << " ";
		zip1 = ss.str();
		ss.str(std::string());
		
		for (auto pair : zip(zip(range(1, 4), string("xyz")), zip(string("abc"), range(6, 9))))
			ss << pair<< " ";
		zip2 = ss.str();
		ss.str(std::string());
		/*
		for (auto pair : zip(chain(range('a','b'),string("adc")), product(range(4,7),string("ko"))))
			ss << pair;
		zip3 = ss.str();
		ss.str(std::string());
		*/
		/*
		for (auto pair : zip(powerset(range(1,3)), powerset(range(4,6))))
			ss << pair;
		zip4 = ss.str();
		ss.str(std::string());
		*/
		for (auto pair : zip(range(1,1),range(1,1)))
			ss << pair;
		zip5 = ss.str();
		ss.str(std::string());

		testcase.setname("Zip test")
			.CHECK_EQUAL(zip1, zipAns1)
			.CHECK_EQUAL(zip2, zipAns2)
			//.CHECK_EQUAL(zip3, zipAns3)
			//.CHECK_EQUAL(zip4, zipAns4)
			.CHECK_EQUAL(zip5, AnsEmpty);
		
		for (auto pair : product(range(1, 4), string("hello")))
			ss << pair << " ";
		product1 = ss.str();
		ss.str(std::string());
		
		for (auto pair : product(product(range(1, 4), range('a','b')),product(string("ah"),range(1,4))))
			ss << pair << " ";
		product2 = ss.str();
		ss.str(std::string());

		for (auto pair : product(range(1,1),range(1,1)))
			ss << pair;
		product3 = ss.str();
		ss.str(std::string());

		testcase.setname("Product test")
			.CHECK_EQUAL(product1, productAns1)
			.CHECK_EQUAL(product2, productAns2)
			.CHECK_EQUAL(product3, AnsEmpty);
		

		for (auto subset : powerset(range(1, 4)))
			ss << subset;
		powerset1 = ss.str();
		ss.str(std::string());

		for (auto subset : powerset(chain(range('a', 'c'), range('x', 'z'))))
			ss << subset;
		powerset2 = ss.str();
		ss.str(std::string());

		for (auto subset : powerset(powerset(range(1,3))))
			ss << subset << " ";
		powerset3 = ss.str();
		ss.str(std::string());

		for (auto subset : powerset(range(1, 1)))
			ss << subset;
		powerset4 = ss.str();
		ss.str(std::string());

		testcase.setname("Powerset test")
			.CHECK_EQUAL(powerset1, powersetAns1)
			.CHECK_EQUAL(powerset2, powersetAns2)
			.CHECK_EQUAL(powerset3, powersetAns3)
			.CHECK_EQUAL(powerset4, EmptyPowersetAns);
		
		grade = testcase.grade();
	}
	else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;
}
