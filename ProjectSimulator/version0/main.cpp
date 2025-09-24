#include <iostream>
#include <fstream>

bool readinfotxt(int& x,int& y,int& varrange) {
    std::ifstream file("info.txt");
    
    if (!file) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return false;
    }
    
    file >> x >> y >> varrange;
    
    if (file.fail()) {
        std::cerr << "Ошибка чтения чисел из файла!" << std::endl;
        return false;
    }
    //проверка значений
    //std::cout << "x = " << x << ", y = " << y << ", varrange = " << varrange << std::endl;
    return true;
}

bool хуnotoverflow(int& x,int& y,int& maxsize){
    if(x<1){
        x=-x;
        //теперь x положительный
    }
    if(y<1){
        y=-y;
        //теперь y положительный
    }
    
    if(x==0 or y==0){
        //длинна или ширина = 0;
        std::cout << "длинна или ширина = 0" <<std::endl;
        return false;
    }
    
    maxsize=0;
    int maxsizetest=2147483647-10;
    //нахождение maxsize 
    //на телефоне 2147483647
    while(true){
        maxsizetest=maxsizetest+1;
        if(maxsizetest<maxsize){
            break;
        }
        maxsize=maxsizetest;
    }
    if(x>(maxsize/y)){
        return false;
    }
    std::cout << "maxsize:" <<maxsize <<std::endl;
    return true;
}

bool varsizeinbit(int varrange, int& varbit){
    varbit=0;
    //проверить будет ли работать при varrange=maxsize
    int i=1;   
    while(true){
        i=i*2;
        varbit=varbit+1;
        if(varrange<=i){
            break;
            }
    }
    i=0;
    
    return true;
};

bool createfilemap(int x,int y,int varbit){
    std::ofstream file("map1.data", std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка создания файла map1.data!" << std::endl;
        return false;
    }

    // Вычисляем общее количество бит
    long long totalBits = (long long)x * y * varbit;
    // Вычисляем количество байт (округляем вверх)
    long long totalBytes = (totalBits + 7) / 8;

    // Заполняем файл нулевыми байтами
    for (long long i = 0; i < totalBytes; ++i) {
        file.put(0);
    }

    if (file.fail()) {
        std::cerr << "Ошибка записи в файл map1.data!" << std::endl;
        return false;
    }

    std::cout << "Файл map1.data успешно создан, размер: " << totalBytes << " байт" << std::endl;
    return true;
};

int main(){
    int x, y,varrange,maxsize,varbit;
    x=0;
    y=0;
    varrange=0;
    maxsize=0;
    varbit=0;
    if(readinfotxt(x,y,varrange)){
        //здесь мы получаем  x,y,varrange
        if(хуnotoverflow(x,y,maxsize)){
            std::cout << "всë исправно работает" <<std::endl;
            std::cout << "x = " << x << ", y = " << y << ", varrange = " << varrange << std::endl;
            if (varsizeinbit(varrange,varbit)){
                //количество необходимых 0 в конце побитовой записи
                //std::cout << (varbit * (x*y))%8<<std::endl;
                if(createfilemap(x,y,varbit)){
                    //win
                }    
            }
        } 
    }; 
    return 0;
}