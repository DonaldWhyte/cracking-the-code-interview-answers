#include <string>
#include <unordered_map>

bool isUnique1(const std::string& str)
{
    // Using dynamically size hash map.
    // O(n) time complexity, O(n) spatial complexity
    typedef std::unordered_set<char> CharSet;
    CharSet usedChars;

    std::string::const_iterator ch = str.begin();
    for (; ch != str.end(); ++ch) {
        if (counts.find(*ch) == counts.end()) {
            counts.insert(*ch);
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

    std::string::const_iterator ch = str.begin();
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

    std::string::const_iterator prevCh = str.begin();
    std::string::const_iterator ch = prevCh + 1; // safe, because of check above

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



int main(int argc, char* argv[])
{
    // Parse command line arguments
    if (argc < 1) {
        std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
        return 1;
    }
    std::string str = argv[1];

    // Define test cases
    std::pair<std::string, bool> cases[] = [
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
        std::make_pair("this_are-gud", true),
    ];
    size_t numCases = sizeof(std::pair<std::string, bool>) / sizeof(cases);

    // Test each implementation
    for (size_t i = 0; i < numCases; ++i) {
        bool output = isUnique1(cases[i].first);
        if (output != cases[i].second) {
            std::cout << "Case " << i << ": "
                      << output << " != " << cases[i].second << std::endl;
        }
    }

    return 0;
}
