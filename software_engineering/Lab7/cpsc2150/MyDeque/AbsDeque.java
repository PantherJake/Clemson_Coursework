package cpsc2150.MyDeque;

public abstract class AbsDeque<T> implements IDeque<T> {

    @Override
    public String toString() {
        String temp = "";
        for(int i = 1; i < this.length()+1; ++i) {
            temp += this.get(i);
            if(this.length() > 1 && i < this.length()) temp += ", ";
        }
        return "<" + temp + ">";
    }
}
