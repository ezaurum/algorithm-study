// 이진 탐색 트리
class Node{
    constructor(data, left, right){
        this.data = data;
        this.left = left;
        this.right = right;        
    }
    show() {
        return this.data;
    }
}

class BST{
    constructor(){
        this.root = null;
    }

    // 루트 확인
    getRoot() {
        return this.root;
    }

    // 삽입
    insert(data) { // type : number
        // 새로운 node 생성
        let n = new Node(data, null, null);

        // 루트 노드가 null이면 생성한 노드가 root
        if (this.root === null) {
            this.root = n;
        } else {
            let current = this.root;
            let parent;

            while(true) {
                parent = current;
                if (data < current.data) {
                    current = current.left;
                    if (current === null) {
                        parent.left = n;
                        break;
                    }
                } else {
                    current = current.right;
                    if(current === null) {
                        parent.right = n;
                        break;
                    }
                }
            }
        }
    }

    // 중위순회 (왼쪽자식, 현재노드, 오른쪽 자식 순으로 탐색)
    inOrder(node) {
        if(node !== null) {
            this.inOrder(node.left);
            console.log(node.show());
            this.inOrder(node.right);
        }
    }

    // 전위순회 (현재노드, 왼쪽자식, 오른족자식)
    preOrder(node) {
        if (node !== null) {
            console.log(node.show());
            this.preOrder(node.left);
            this.preOrder(node.right);
        }
    }

    // 후위순회 (왼쪽자식 오른쪽 자식 , 현재노드)
    postOrder(node) {
        if (node !== null) {
            this.postOrder(node.left);
            this.postOrder(node.right);
            console.log(node.show());
        }
    }

    find(data) {
        let current = this.root;
        while(current.data !== data) {
            if (data < current.data) {
                current = current.left;
            } else {
                current = current.right;
            }

            if (current === null) {
                return null;
            }
        }
    }

    remove(data) {
        this.root = this.removeNode(this.root, data);
    }

    removeNode(node, data) {
        if (node === null) {
            return null;
        }
        if (data === node.data) {
            // 자식이 없을때
            if(node.left === null && node.right === null) {
                return null;
            }

            // 왼쪽 자식이 없을때
            if(node.left === null) {
                return node.right;
            }

            // 오른쪽 자식이 없을때
            if(node.right === null) {
                return node.left;
            }

            // 둘다 자식이 있을땨
            let tempNode = this._getSmallest(node.right);
            node.data = tempNode.data;
            node.right = this.removeNode(node.right, tempNode.data);

            return node;
        } else if(data < node.data) {
            node.left = this.removeNode(node.left, data);
            return node;
        } else {
            node.right = this.removeNode(node.right, data);
            return node;
        }
    }

    _getSmallest(node) {
        let current = node;
        while(!(current.left === null)){
            current = current.left;
        }
        return current;
    }
}

const nums = new BST();
nums.insert(23);
nums.insert(45);
nums.insert(15);
nums.insert(37);
nums.insert(3);
nums.insert(99);
nums.insert(21);
nums.insert(40);
nums.insert(44);
nums.insert(1);
nums.insert(65);

console.log(nums.inOrder(nums.getRoot()))
console.log("==========");
console.log(nums.find(45)); 
console.log(nums.find(2));
nums.remove(45);
nums.inOrder(nums.getRoot());
