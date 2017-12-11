#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton {
private:
	static T *instance;

protected:
	Singleton() { }
	virtual ~Singleton() { }

public:
	static T *getInstance();
	static void destroy();
};

template<typename T>
T* Singleton<T>::instance = nullptr;

template<typename T>
T* Singleton<T>::getInstance() {
	if(instance == nullptr) {
		instance = new T();
	}

	return instance;
}

template<typename T>
void Singleton<T>::destroy() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

#endif // SINGLETON_H
