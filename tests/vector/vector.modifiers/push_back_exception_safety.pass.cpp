#include "myUnitTest.hpp"

static bool gCopyConstructorShouldThrow = false;

class CMyClass
{
	public:

		CMyClass(int tag, std::stringstream & o_string, int & passed, int & failed) :
		        fMagicValue(kStartedConstructionMagicValue),
		        fTag(tag),
				output_string(o_string),
				test_passed(passed),
				test_failed(failed)
		{
			// Signal that the constructor has finished running
			fMagicValue = kFinishedConstructionMagicValue;
		}

		CMyClass(const CMyClass &iOther) :
		        fMagicValue(kStartedConstructionMagicValue),
		        fTag(iOther.fTag),
				output_string(iOther.output_string),
				test_passed(iOther.test_passed),
				test_failed(iOther.test_failed)
		{
			// If requested, throw an exception _before_ setting fMagicValue to kFinishedConstructionMagicValue
			if (gCopyConstructorShouldThrow)
				throw std::exception();
			// Signal that the constructor has finished running
			fMagicValue = kFinishedConstructionMagicValue;
		}

		~CMyClass()
		{
			// Only instances for which the constructor has finished running should be destructed
			ASSERT(fMagicValue == kFinishedConstructionMagicValue);
		}
		bool
		equal(const CMyClass &rhs) const
		{
			return fTag == rhs.fTag && fMagicValue == rhs.fMagicValue;
		}

        void print() const {
            std::cout << fTag << " | " << fMagicValue << '\n';
        }

	private:
		int fMagicValue;
		int fTag;
		std::stringstream & output_string;
		int & test_passed;
		int & test_failed;

	private:
		static int kStartedConstructionMagicValue;
		private:
		static int kFinishedConstructionMagicValue;
};

// Value for fMagicValue when the constructor has started running, but not yet finished
int CMyClass::kStartedConstructionMagicValue = 0;
// Value for fMagicValue when the constructor has finished running
int CMyClass::kFinishedConstructionMagicValue = 12345;

bool operator == (const CMyClass &lhs, const CMyClass &rhs) {
	return lhs.equal(rhs);
}

TEST_CASE(Vector, Modifiers, PushBackExceptions, {
	{
		CMyClass instance(42, output_string, test_passed, test_failed);
		VECTOR<CMyClass> vec;
std::cout << "----------\n";
instance.print();
std::cout << "----------\n";
		vec.push_back(instance);
vec[0].print();
		VECTOR<CMyClass> vec2(vec);
vec2[0].print();
		gCopyConstructorShouldThrow = true;
std::cout << vec.size() << " " << vec2.size() << "\n";
vec[0].print();
		ASSERT_EXCEPT(vec.push_back(instance))
std::cout << vec.size() << " " << vec2.size() << "\n";
vec[0].print();

		ASSERT(vec == vec2)
	} ASSERT_AWARENESS
})
