#include <iostream>

class Strategy {
public:
	Strategy() {}
	virtual int doOperation(int num1, int num2) = 0;

}; 

static Strategy* _strategy = 0;

class OperationAdd : public Strategy {
	//@Override
public:
	OperationAdd():Strategy() {}
	int doOperation(int num1, int num2) {
		return num1 + num2;
	}
};

class OperationSubstract : public Strategy {
	//@Override
public:
	OperationSubstract() :Strategy() {}
	int doOperation(int num1, int num2) {
		return num1 - num2;
	}
};

class OperationMultiply : public Strategy {
	//@Override
public:
	OperationMultiply() :Strategy() {}
	int doOperation(int num1, int num2) {
	return num1 * num2;
	}
};

class Context {
public:
	Context(Strategy* strategy) {
		_strategy = strategy;
	}

	static int executeStrategy(int num1, int num2) {
		return _strategy->doOperation(num1, num2);
	}
};

	int main() {
		Context* context = new Context(new OperationAdd());
		std::cout << "10 + 5 = " << Context::executeStrategy(10, 5) << '\n';
		context = new Context(new OperationSubstract());
		std::cout << "10 - 5 = " << Context::executeStrategy(10, 5) << '\n';
		context = new Context(new OperationMultiply());
		std::cout << "10 * 5 = " << Context::executeStrategy(10, 5) << '\n';
		return 0;
	}