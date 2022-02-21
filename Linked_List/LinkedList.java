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
      System.out.print(current.data + " ");
      current = current.next;
    }
    System.out.println("");
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

  public void addTail(int value) {
    Node node = new Node();
    node.data = value;
    if (head == null) {
      head = node;
    } else {
      tail.next = node;
    }
    tail = node;
  }

  public Node getNode(int value) {
    Node current = head;
    while (current != null) {
      if (current.data == value) {
        System.out.println("Value found.");
        return current;
      }
      current = current.next;
    }
    System.out.println("Value not found.");
    return null;
  }

  public static void main(String[] args) {
    LinkedList list = new LinkedList();
    list.addHead(1);
    list.addHead(2);
    list.addHead(5);
    list.addHead(4);
    list.addHead(6);
    list.displayList();
    list.addTail(3);
    list.addTail(7);
    list.displayList();
    list.getNode(3);
  }
}