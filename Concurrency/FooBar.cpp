class FooBar {
private:
    int n;
    std::mutex fooMutex;
    std::mutex barMutex;

public:
    FooBar(int n) {
        this->n = n;
        barMutex.lock();
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
            fooMutex.lock();
        	printFoo();
            barMutex.unlock();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
            barMutex.lock();
        	printBar();
            fooMutex.unlock();
        }
    }
};