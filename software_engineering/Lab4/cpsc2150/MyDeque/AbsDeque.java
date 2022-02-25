package cpsc2150.MyDeque;

public abstract class AbsDeque implements IDeque {

    @Override
    public String toString() {
        String temp = "";
        for(int i = 0; i < length(); ++i) {
            temp += get(i);
            if(length() > 1 && i < length()-1) temp += ", ";
        }
        return "< " + temp + " >";
    }
}
