#include<iostream>
#include<string>
#include<vector>



class Programmer {
public:
	virtual void do_work() = 0;
	virtual ~Programmer() = default;
};
class FrontendProgrammer :public Programmer {
protected:
	std::string target;
public:
	void do_work() {
		std::cout << "developing " << target<< std::endl;
	}
	~FrontendProgrammer()=default;
	FrontendProgrammer(std::string target): Programmer(),target{target}{}
};
class WebProgrammer :public FrontendProgrammer {
protected:
	std::string name_site;
public:
	void do_work() {
		std::cout <<" Website development - " << name_site<< std::endl;
	}
	~WebProgrammer() = default;
	WebProgrammer(std::string name_site) :FrontendProgrammer("site"), name_site{ name_site }{}
};
class SystemProgrammer :public Programmer {
protected:
	std::string name_os;
public:
	 void do_work(){
		std::cout << "development operating systems - " <<name_os << std::endl;
	}
	SystemProgrammer() = default;
	SystemProgrammer(std::string name_os):Programmer(), name_os{name_os}{}
};

int main(){
	std::vector<Programmer*>programmers;
	std::cout << "Enter target for Frontend programmer(site or app):";
	std::string target;
	while (true) {
		std::getline(std::cin, target);
		if (target != "site" && target != "app") {
			std::cout << "site or app" << std::endl;
		}
		else break;
	}
	programmers.push_back(new FrontendProgrammer(target));
	std::cout << "Enter site name for Web programmer:";
	std::string name_site;
	std::getline(std::cin, name_site);
	programmers.push_back(new WebProgrammer(name_site));
	std::cout << "Enter operating system name for System programmer:";
	std::string name_os;
	std::getline(std::cin, name_os);
	programmers.push_back(new SystemProgrammer(name_os));
	for (int i = 0; i < programmers.size(); i++) {
		programmers[i]->do_work();
		delete programmers[i];
	 }
	
	return 0;
}