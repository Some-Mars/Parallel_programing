#include <iostream>
#include <vector>
#include <time.h>
#include <thread>
#include <chrono>
#include <atomic>

const int mineIterations = 100000;

using namespace std;

void mineXryuCoin(atomic<float>* coin){
    while(*coin <=1){
        for(int i = 0; i < mineIterations; i++);
        // atomic_fetch_add(coin, 0.01);
        coin->fetch_add(0.01);
    }
}

int main(){
    // Количество Хрюкоина до начала майнинга
    atomic<float> xryu_coin = 0.0;
    
    //Вектор содержащий число потоков
    vector<int> threadsAmount = {1, 2, 4};
    // Создаём вектор нужного числа потоков
    for(size_t j = 0; j < threadsAmount.size(); j++){
        vector<thread> threads;
        // Добавляем потоки
        for(int k = 0; k <threadsAmount[j]; k++){
            threads.emplace_back(mineXryuCoin, &(xryu_coin));
        }
        
        // Старт таймера
        clock_t startTime = clock();
        
        // Запускается майнинг
        for(thread& th: threads){
            th.join();
        }
        
        // Конец таймера
        clock_t endTime = clock();
        double deltaTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
        
        cout << "Кол-во потоков: " << threadsAmount[j] << ", Секунд для майнинга 1 Хрюкоина: " << deltaTime << " секунд." << endl;
        cout << "Дней до Хрюкоин-миллионерства: " << deltaTime*1000000 << endl;
        xryu_coin = 0.0;
    }
    
    return 0;
}