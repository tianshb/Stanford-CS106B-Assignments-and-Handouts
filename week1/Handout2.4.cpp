char MostFrequentCharacter(ifstream &in, int &numOccurrences)
{
    Map<int> charFrequencies;
    numOccurrences = 0;
    int nextChar;
    while((nextChar = in.get()) != EOF)
    {
        // convert it to a string for lookup in the symbol table
        string foundChar = "";
        foundChar += char(nextChar);
        // if we find it, incremement the stored value, otherwise
        // enter in a new one
        int frequency = 1;
        if (charFrequencies.containsKey(foundChar))
            frequency = charFrequencies[foundChar] + 1;
        charFrequencies[foundChar] = frequency;
    }
    // now use an iterator to find the most occurring character
    Map<int>::Iterator it = charFrequencies.iterator();
    string maxCharacter = "";
    while (it.hasNext())
    {
        string character = it.next();
        int frequency = charFrequencies[character];
        if (frequency > numOccurrences)
        {
            maxCharacter = character;
            numOccurrences = frequency;
        }
    }
    return maxCharacter[0];
}