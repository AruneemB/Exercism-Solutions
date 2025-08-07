import java.util.ArrayList;
import java.util.LinkedHashSet;

class IsogramChecker {

    boolean isIsogram(String phrase) 
    {       
        phrase = removeOccurrences(phrase, ' ');
        phrase = removeOccurrences(phrase, '-');
        phrase = phrase.toLowerCase();
        
        char [] phraseChars = phrase.toCharArray();
        LinkedHashSet<Character> charsHashSet = new LinkedHashSet<>(phraseChars.length);

        for(char phraseChar : phraseChars) charsHashSet.add(phraseChar);

        String setPhrase = "";
        for(char phraseChar : charsHashSet) setPhrase += phraseChar;

        return(phrase.equals(setPhrase));
    }

    public static String removeOccurrences(String phrase, Character character)
    {
        ArrayList<Character> phraseCharacters = new ArrayList<>();
        char [] phraseChars = phrase.toCharArray();

        for(char phraseChar : phraseChars) if(phraseChar != character) phraseCharacters.add(phraseChar);

        StringBuilder stringBuilder = new StringBuilder();
        for(char phraseCharacter : phraseCharacters) stringBuilder.append(phraseCharacter);

        return stringBuilder.toString();
        
    }
}
