
import java.util.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Is_LinkedList_Palindrom {
    Node head;

    void printList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public void addToTheLast(Node node) {
        if (head == null) {
            head = node;
        } else {
            Node temp = head;
            while (temp.next != null)
                temp = temp.next;
            temp.next = node;
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t > 0) {
            int n = sc.nextInt();
            Is_LinkedList_Palindrom llist = new Is_LinkedList_Palindrom();
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            llist.addToTheLast(head);
            for (int i = 1; i < n; i++) {
                int a = sc.nextInt();
                llist.addToTheLast(new Node(a));
            }

            Palindrome g = new Palindrome();
            if (g.isPalindrome(llist.head) == true)
                System.out.println(1);
            else
                System.out.println(0);
            t--;
        }

    }
}

class Palindrome {
    static Node reverse(Node head) {
        Node prev = null;
        Node current = head;
        Node next;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    static boolean compare(Node head, Node p) {
        while (head != null && p != null) {
            if (head.data != p.data) {
                return false;
            }
            head = head.next;
            p = p.next;
        }
        if (head != null || p != null)
            return false;
        return true;
    }

    boolean isPalindrome(Node head) {
        boolean ans = false;
        int n = 0;
        Node p = head;
        while (p != null) {
            p = p.next;
            n++;
        }
        if(n==1 || (n==2 && head.data == head.next.data))
            return true;
        Node middle = head;
        for (int i = 0; i < n / 2 - 1; i++)
            middle = middle.next;

        Node fh = middle;
        middle = middle.next;
        fh.next = null;

        Node midNode = null;
        if (n % 2 == 1) {
            midNode = middle;
            middle = middle.next;
        }

        p = reverse(middle);
        ans = compare(head, p);
        middle = reverse(p);

        if (midNode!=null) {
            fh.next = midNode;
            fh = fh.next;
        }
        fh.next = middle;
        return ans;
    }
}
