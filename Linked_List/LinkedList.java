public class LinkedList {
  private class Node {
    int data;
    Node next;
  }
  public Node head = null;
  public Node tail = null;
  public void displayList() {
    System.out.println("Displaying current list: ");
    Node current = head;
    while (current != null) {
      System.out.println(current.data);
      current = current.next;
    }
  }
  public void addHead(int value) {
    Node node = new Node();
    node.data = value;
    if (head == null) {
      node.next = null;
      tail = node;
    } else {
      node.next = head;
    }
    head = node;
  }

  public static void main(String[] args) {
    LinkedList list = new LinkedList();
    list.addHead(1);
    list.addHead(2);
    list.displayList();
  }
}