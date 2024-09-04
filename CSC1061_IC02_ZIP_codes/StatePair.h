// Header file for State Pair class

#ifndef STATEPAIR
#define STATEPAIR_H

using namespace std;

template<typename T1, typename T2>
class StatePair {
public:
	//constructors
	StatePair();
	StatePair(T1 userKey, T2 userValue);
	void setKey(T1 newKey) { key = newKey; }
	void setValue(T2 newValue) { value = newValue; }
	T1 getKey() { return key; }
	T2 getValue() { return value; }

	// helper function
	void printInfo();

private:
	T1 key;
	T2 value;
};

template<typename T1, typename T2>
StatePair<T1, T2>::StatePair() {}

template<typename T1, typename T2>
StatePair<T1, T2>::StatePair(T1 userKey, T2 userValue) {
	key = userKey;
	value = userValue;
}

template<typename T1, typename T2>
void StatePair<T1, T2>::printInfo() {
	cout << key << " : " << value << endl;
}

#endif

