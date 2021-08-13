#include<iostream>

using namespace std;

namespace loaders
{
    inline 	namespace basic_loader {
		class loader {
		public:
			loader() {
				cout << "Constructing gen1 virtual loader" << endl;
			};
			void load() {
				cout << "Loading virtual file" << endl;

			}
		};
	};

	namespace advanced_loader {
		class load_rtl {
		public:
			load_rtl() {}
			void load() {
				cout << "Loading RTL file" << endl;
			}
		};
		class loader {
			load_rtl rl;
		public:
			loader() {
				cout << "Constructing advanced loader" << endl;
			}
			void load() {
				cout << "Loading virtual file" << endl;
				rl.load();

			}
		};
	};
}


int main() 
{

	//Traditional Method
	loaders::basic_loader::loader bl;
	bl.load();
	loaders::advanced_loader::loader al;
	al.load();

	//Using thelined loader
	loaders::loader l;
	l.load();
	//Make advanced_loader namespace as inlined to switch to advance loader by default
	//Cannot make both namesoaces inline as it will make loader class ambigous


}


