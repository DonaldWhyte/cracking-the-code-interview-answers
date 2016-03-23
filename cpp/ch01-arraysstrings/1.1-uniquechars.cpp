#include <string>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <iostream>

bool isUnique1(const std::string& str)
{
    // Using dynamically size hash map.
    // O(n) time complexity, O(n) spatial complexity
    std::unordered_set<char> usedChars;

    auto ch = str.begin();
    for (; ch != str.end(); ++ch) {
        if (usedChars.find(*ch) == usedChars.end()) {
            usedChars.insert(*ch);
        } else {
            return false;
        }
    }

    return true;
}

bool isUnique2(const std::string& str)
{
    // Using fixed-size count map.
    // O(n) time complexity, O(1) spatial complexity (but large constant factor)
    // Only works if string characters are ASCII, and not unicode.
    int counts[256] = { 0 };

    auto ch = str.begin();
    for (; ch != str.end(); ++ch) {
        int& chCount = counts[*ch];
        if (++chCount > 1) {
            return false;
        }
    }

    return true;
}

bool isUnique3(std::string& str)
{
    // O(nlogn) time complexity, O(1) spatial complexity
    // Using inplace sort means we allocate *no* additional memory, at the cost
    // of modifyng the original string.
    std::sort(str.begin(), str.end());

    // The for-loop later in the function assumes length >= 2, so we catch
    // that case here.
    if (str.length() < 2) {
        return true;
    }

    auto prevCh = str.begin();
    auto ch = prevCh + 1; // safe, because of check above

    for (; ch != str.end(); ++prevCh, ++ch) {
        if (*prevCh == *ch) {
            return false;
        }
    }

    return true;
}

bool isUnique4(const std::string& str)
{
    // O(nlogn) time complexity, O(n) spatial complexity
    // Have to copy string before sorting, so still O(n). Most likely there's
    // a lower constant factor than the two implementations above.
    std::string sortedStr = str;
    std::sort(sortedStr.begin(), sortedStr.end());

    return isUnique3(sortedStr);
}



void printBanner(const std::string& banner)
{
    std::cout << banner << "\n"
              << "============================================================"
              << std::endl;
}


int main(int argc, char* argv[])
{
    // Define test cases
    typedef std::pair<std::string, bool> TestCase;
    TestCase cases[] = {
        std::make_pair("", true),
        std::make_pair("a", true),
        std::make_pair("ab", true),
        std::make_pair("ba", true),
        std::make_pair("aa", false),
        std::make_pair("abc", true),
        std::make_pair("aab", false),
        std::make_pair("aba", false),
        std::make_pair("abb", false),
        std::make_pair("sdjfhuygrufge79irhtroefr", false),
        std::make_pair("this-are_gud", true)
    };
    size_t numCases = sizeof(cases) / sizeof(TestCase);

    // Test each implementation

    printBanner("isUnique1");
    for (size_t i = 0; i < numCases; ++i) {
        bool output = isUnique1(cases[i].first);
        if (output != cases[i].second) {
            std::cerr << "Case " << i << " with input " << cases[i].first
                      << ": " << output << " != " << cases[i].second
                      << std::endl;
        }
    }

    printBanner("isUnique2");
    for (size_t i = 0; i < numCases; ++i) {
        bool output = isUnique2(cases[i].first);
        if (output != cases[i].second) {
            std::cerr << "Case " << i << " with input " << cases[i].first
                      << ": " << output << " != " << cases[i].second
                      << std::endl;
        }
    }

    printBanner("isUnique3");
    for (size_t i = 0; i < numCases; ++i) {
        // this one mutates the input, so it's copied to prevent other tests
        // being affected
        std::string copyOfInput = cases[i].first;

        bool output = isUnique3(copyOfInput);
        if (output != cases[i].second) {
            std::cerr << "Case " << i << " with input " << copyOfInput
                      << ": " << output << " != " << cases[i].second
                      << std::endl;
        }
    }

    printBanner("isUnique4");
    for (size_t i = 0; i < numCases; ++i) {
        bool output = isUnique4(cases[i].first);
        if (output != cases[i].second) {
            std::cerr << "Case " << i << " with input " << cases[i].first
                      << ": " << output << " != " << cases[i].second
                      << std::endl;
        }
    }

    return 0;
}
