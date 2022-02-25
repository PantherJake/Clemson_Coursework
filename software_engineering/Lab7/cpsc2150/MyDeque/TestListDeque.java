package cpsc2150.MyDeque;

import static org.junit.Assert.*;

import org.junit.Test;

public class TestListDeque {
    private IDeque<Character> MakeADeque() {
        return new ListDeque<>();
    }

    // enqueue
    @Test
    public void test_enqueue_4law() {
        // Tests enqueue for a random deque
        IDeque q = MakeADeque();
        Character input1 = '4';
        Character input2 = 'l';
        Character input3 = 'a';
        Character input4 = 'w';

        q.enqueue(input1);
        q.enqueue(input2);
        q.enqueue(input3);
        q.enqueue(input4);

        String expected = "<4, l, a, w>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_enqueue_max() {
        // Tests enqueue until the deque is maxed out (and then goes some)
        IDeque q = MakeADeque();
        Character input1 = 'A';
        for(int i = 0; i < 100; ++i) q.enqueue(input1);

        String expected = "<";
        for(int i = 0; i < 100; ++i) {
            expected += 'A';
            if(i < 99) expected += ", ";
        }
        expected += '>';

        assertEquals(expected, q.toString());
    }

    @Test
    public void test_enqueue_single() {
        // Tests enqueue for a single element into a deque
        IDeque q = MakeADeque();
        Character input1 = '?';
        q.enqueue(input1);

        String expected = "<?>";
        assertEquals(expected, q.toString());
    }

    // dequeue
    @Test
    public void test_dequeue_1789sb() {
        // Tests dequeue on a random deque
        IDeque q = MakeADeque();
        Character input1 = '1';
        Character input2 = '7';
        Character input3 = '8';
        Character input4 = '9';
        Character input5 = 's';
        Character input6 = 'b';
        Character input7 = 'w';

        q.enqueue(input1);
        q.enqueue(input2);
        q.enqueue(input3);
        q.enqueue(input4);
        q.enqueue(input5);
        q.enqueue(input6);
        q.enqueue(input7);

        q.dequeue();
        q.dequeue();

        String expected = "<8, 9, s, b, w>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_dequeue_max() {
        // Tests dequeue on a full deque
        IDeque q = MakeADeque();
        Character input1 = 'A';
        for(int i = 0; i < 100; ++i) q.enqueue(input1);
        q.dequeue();

        String expected = "<";
        for(int i = 0; i < 99; ++i) {
            expected += 'A';
            if(i < 98) expected += ", ";
        }
        expected += '>';

        assertEquals(expected, q.toString());
    }

    @Test
    public void test_dequeue_single() {
        // Tests dequeue on a deque with one element and tests for the character as well
        IDeque q = MakeADeque();
        Character input1 = '?';
        q.enqueue(input1);
        q.dequeue();

        String expected = "<>";

        assertEquals(expected, q.toString());
    }

    // inject
    @Test
    public void test_inject_432I() {
        // Tests injecting random elements into a deque
        IDeque q = MakeADeque();
        Character input1 = '4';
        Character input2 = '3';
        Character input3 = '2';
        Character input4 = 'I';

        q.inject(input1);
        q.inject(input2);
        q.inject(input3);
        q.inject(input4);

        String expected = "<I, 2, 3, 4>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_inject_max() {
        // Tests injecting elements until the deque is maxed out (and then some)
        IDeque q = MakeADeque();

        Character input1 = 'B';
        for(int i = 0; i < 100; ++i) q.inject(input1);

        String expected = "<";
        for(int i = 0; i < 100; ++i) {
            expected += 'B';
            if(i < 99) expected += ", ";
        }
        expected += '>';

        assertEquals(expected, q.toString());
    }

    @Test
    public void test_inject_single() {
        // Tests injecting an element into an empty deque (difference is the toString wont have comma)
        IDeque q = MakeADeque();
        Character input1 = 'c';
        q.inject(input1);

        String expected = "<c>";
        assertEquals(expected, q.toString());
    }

    // remove last
    @Test
    public void test_remove_last_clemmy() {
        // Tests removing last from a random deque
        IDeque q = MakeADeque();
        Character input1 = 'c';
        Character input2 = 'l';
        Character input3 = 'e';
        Character input4 = 'm';
        Character input5 = 'm';
        Character input6 = 'y';

        q.enqueue(input1);
        q.enqueue(input2);
        q.enqueue(input3);
        q.enqueue(input4);
        q.enqueue(input5);
        q.enqueue(input6);

        q.removeLast();
        q.removeLast();

        String expected = "<c, l, e, m>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_remove_last_lol() {
        // Tests remove last to check for the character returned from removeLast against expected
        IDeque q = MakeADeque();
        Character input1 = 'l';
        Character input2 = 'o';
        Character input3 = 'l';

        q.inject(input1);
        q.inject(input2);
        q.inject(input3);

        Character a = (Character)q.removeLast();

        Character expected = 'l';
        assertEquals(expected, a);
    }

    @Test
    public void test_remove_last_single() {
        // Tests remove last on a deque with only one element
        IDeque q = MakeADeque();
        Character input1 = ']';

        q.inject(input1);
        q.removeLast();

        String expected = "<>";
        assertEquals(expected, q.toString());
    }

    // clear
    @Test
    public void test_clear_max() {
        // Tests clear on a full deque
        IDeque q = MakeADeque();
        Character input1 = 'A';
        for(int i = 0; i < 100; ++i) q.enqueue(input1);
        q.clear();

        String expected = "<>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_clear_90210() {
        // Tests clear on a deque with random length
        IDeque q = MakeADeque();
        Character input1 = '9';
        Character input2 = '0';
        Character input3 = '2';
        Character input4 = '1';
        Character input5 = '0';

        q.enqueue(input1);
        q.enqueue(input2);
        q.enqueue(input3);
        q.enqueue(input4);
        q.enqueue(input5);

        q.clear();

        String expected = "<>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_clear_empty() {
        // Tests clear on an empty deque
        IDeque q = MakeADeque();
        q.clear();

        String expected = "<>";
        assertEquals(expected, q.toString());
    }

    // peek
    @Test
    public void test_peek_6969() {
        // Tests peek on a random deque
        IDeque q = MakeADeque();
        q.enqueue('6');
        q.enqueue('9');
        q.enqueue('6');
        q.enqueue('9');

        Character expected = '6';
        assertEquals(expected, q.peek());
    }

    @Test
    public void test_peek_max() {
        // Tests peek on a deque that is maxed out
        IDeque q = MakeADeque();
        Character input1 = 'A';
        for(int i = 0; i < 100; ++i) q.enqueue(input1);
        q.dequeue();
        q.inject('l');

        Character expected = 'l';
        assertEquals(expected, q.peek());
    }

    @Test
    public void test_peek_single() {
        // Tests peek on a deque with only one element
        IDeque q = MakeADeque();
        q.enqueue('k');

        Character expected = 'k';
        assertEquals(expected, q.peek());
    }

    // end of deque
    @Test
    public void test_endOfDeque_sierra117() {
        // Tests endOfDeque on a random deque
        IDeque q = MakeADeque();
        Character input1 = 's';
        Character input2 = 'i';
        Character input3 = 'e';
        Character input4 = 'r';
        Character input5 = 'r';
        Character input6 = 'a';
        Character input7 = '1';
        Character input8 = '1';
        Character input9 = '7';

        q.enqueue(input1);
        q.enqueue(input2);
        q.enqueue(input3);
        q.enqueue(input4);
        q.enqueue(input5);
        q.enqueue(input6);
        q.enqueue(input7);
        q.enqueue(input8);
        q.enqueue(input9);

        Character expected = '7';
        assertEquals(expected, q.endOfDeque());
    }

    @Test
    public void test_endOfDeque_max() {
        // Tests endOfDeque on a full deque
        IDeque q = MakeADeque();
        Character input1 = 'A';
        for(int i = 0; i < 100; ++i) q.enqueue(input1);
        q.dequeue();
        q.enqueue('l');

        Character expected = 'l';
        assertEquals(expected, q.endOfDeque());
    }

    @Test
    public void test_endOfDeque_single() {
        // Tests endOfDeque on a deque with one element
        IDeque q = MakeADeque();
        q.enqueue('k');

        Character expected = 'k';
        assertEquals(expected, q.endOfDeque());
    }

    // insert
    @Test
    public void test_insert_max() {
        // Tests insert on a deque with one element below max (before insert)
        IDeque q = MakeADeque();
        Character input1 = 'A';
        for(int i = 0; i < 100; ++i) q.enqueue(input1);
        q.dequeue();

        q.insert('?', 20);
        Character expected = '?';
        for(int i = 0; i < 100; ++i) {
            if(i == 20) assertEquals(expected, q.get(i));
        }
    }

    @Test
    public void test_insert_single() {
        // Tests insert into an empty deque
        IDeque q = MakeADeque();
        q.insert('j', 1);

        String expected = "<j>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_insert_fun() {
        // Tests insert into a random deque
        IDeque q = MakeADeque();
        q.enqueue('f');
        q.enqueue('n');

        q.insert('u', 2);

        String expected = "<f, u, n>";
        assertEquals(expected, q.toString());
    }

    // remove
    @Test
    public void test_remove_jake() {
        // Tests remove on a random deque
        IDeque q = MakeADeque();
        q.enqueue('j');
        q.enqueue('a');
        q.enqueue('a');
        q.enqueue('k');
        q.enqueue('e');

        q.remove(3);

        String expected = "<j, a, k, e>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_remove_single() {
        // Tests remove on a deque with one element
        IDeque q = MakeADeque();
        q.enqueue('#');

        q.remove(1);

        String expected = "<>";
        assertEquals(expected, q.toString());
    }

    @Test
    public void test_remove_karis() {
        // Tests remove for the returned character against the expected
        IDeque q = MakeADeque();
        q.enqueue('k');
        q.enqueue('a');
        q.enqueue('r');
        q.enqueue('r');
        q.enqueue('i');
        q.enqueue('s');

        Character input = (Character)q.remove(4);

        Character expected = 'r';
        assertEquals(expected, input);
    }

    // get
    @Test
    public void test_get_ggnore() {
        // Tests get on a random deque
        IDeque q = MakeADeque();
        q.enqueue('g');
        q.enqueue('g');
        q.enqueue('n');
        q.enqueue('o');
        q.enqueue('r');
        q.enqueue('e');

        Character expected = 'o';
        assertEquals(expected, q.get(4));
    }

    @Test
    public void test_get_single() {
        // Tests get on a deque with one element
        IDeque q = MakeADeque();
        q.inject('_');

        Character expected = '_';
        assertEquals(expected, q.get(1));
    }

    @Test
    public void test_get_a_lot() {
        // Tests get on a full deque (elements max out early)
        IDeque q = MakeADeque();
        for(int i = 0; i < 25; ++i) {
            q.inject('L');
            q.enqueue('A');
            q.inject('o');
            q.enqueue('?');
        }

        Character expected = 'o';
        assertEquals(expected, q.get(35));
    }
}
