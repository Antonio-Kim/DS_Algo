class Node {
  constructor(value) {
    this.data = value;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
  }

  displayList() {
    console.log("Displaying current list: ");
    let current = this.head;
    while (current != null) {
      process.stdout.write(`${current.data} `);
      current = current.next;
    }
    console.log("");
  }

  addHead(value) {
    let node = new Node(value);
    if (this.head == null) {
      node.next = null;
      this.tail = node;
    } else {
      node.next = this.head;
    }
    this.head = node;
  }

  addTail(value) {
    let node = new Node(value);
    if (this.head == null) {
      this.head = node; 
    } else {
      this.tail.next = node;
    }
    this.tail = node;
  }

  getNode(value) {
    let current = this.head;
    while (current != null) {
      if (current.data == value) {
        console.log("Value found.");
        return current;
      }
      current = current.next;
    }
    console.log("Value not found.");
    return null;
  }

  deleteNode(node) {
    if (this.head == node) {
      if (this.head.next == null) {
        this.head = this.tail = null;
      } else {
        this.head = this.head.next;
      }
    } else {
      let temp = this.head;
      while (temp != null && temp.next != node) {
        temp = temp.next;
      }
      temp.next = node.next;
    }
  }

}

const list = new LinkedList();

list.addHead(1);
list.addHead(2);
list.addHead(5);
list.addHead(4);
list.addHead(6);
list.displayList();
list.addTail(3);
list.addTail(7);
list.displayList();
list.deleteNode(list.getNode(7));
list.deleteNode(list.getNode(6));
list.deleteNode(list.getNode(5));
list.deleteNode(list.getNode(4));
list.displayList();