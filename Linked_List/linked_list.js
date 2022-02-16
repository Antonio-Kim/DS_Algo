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
      console.log(`${current.data}`);
      current = current.next;
    }
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
}

const list = new LinkedList();

list.addHead(1);
list.addHead(2);
list.addHead(5);
list.addHead(4);
list.addHead(6);
list.displayList();