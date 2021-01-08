#include <iostream>
using namespace std;


class String{
	
	public:	
	float thicc;
	
	
	void set_width(float width){
		this->thicc = width;
			if(this->thicc > 3)
				throw "Too thicc string!";
			else if(this->thicc < 0.1)
				throw "Too slim slim!";
	}
	
	
	
};


class Guitar{
	
	String str[6];
	
	public:
	
	void replaceString(float st, int pos){
			
				//printf("%f\n", st);
				try{
				str[pos].set_width(st);
				}catch(const char* msg){	
					printf("%s\n", msg);
				}
	}
};


int main(){
	
	Guitar g1 = Guitar();
		g1.replaceString(0.001, 0);
		g1.replaceString(0.254, 1);
		g1.replaceString(0.381, 2);
		g1.replaceString(0.534, 3);
		g1.replaceString(0.762, 4);
		g1.replaceString(0.965, 5);
	
	/*try{
		String s = String(0.001);
	}
	catch(const char* msg){	
		printf("%s\n", msg);
	}
	*/
		

}




