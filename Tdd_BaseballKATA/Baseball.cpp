#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
private:
	const GuessResult SOVED = { true, 3, 0 };
	string question;

public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return SOVED;
		}
		return getUnsolvedGameResult(guessNumber);
	}

	GuessResult getUnsolvedGameResult(const std::string& guessNumber)
	{
		GuessResult result = { false, 0, 0 };

		result.balls = countBalls(guessNumber);
		result.strikes = countStrikes(guessNumber);

		return result;
	}

	int countStrikes(const std::string& guessNumber)
	{
		int strikeCount = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) {
				strikeCount++;
			}
		}
		return strikeCount;
	}

	int countBalls(const std::string& guessNumber)
	{
		int ballCount = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (guessNumber[i] == question[j]) {
					ballCount++;
				}
			}
		}
		return ballCount;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be numbers.");
		}

		if (isDuplicateNumber(guessNumber))
			throw invalid_argument("Must not habe the same number");
	}

	bool isDuplicateNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
};