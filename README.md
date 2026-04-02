Клас ``LinkedList`` та решта методів була попередньо реалізована у практичній частині.

Посилання на [репозиторії](https://github.com/OlexandraKorol/LinkedLists/blob/main/README.md)

### Завдання 1: Вставка в кінець – insertAtEnd:

```
    void insertAtEnd(T value) {
    Node<T>* newNode = new Node<T>(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node<T>* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
   }

```

результат виконання та тестування у main:

```
10 -> 30 -> nullptr
10 -> 30 -> 10 -> nullptr
10 -> 30 -> 10 -> 20 -> 30 -> nullptr
5 -> 10 -> 30 -> 10 -> 20 -> 30 -> nullptr
5 -> 10 -> 30 -> 10 -> 20 -> 30 -> 40 -> nullptr

```

Метод insertAtEnd має **часову складність O(n)**, 
оскільки необхідно пройти весь список до останнього елемента. 
**Просторова складність — O(1)**, оскільки створюється лише один новий вузол.


### Завдання 2: Розмір списку – getSize:

```
   size_t getSize() const {
        size_t counter{0};

        Node<T>* current = head;

        while (current != nullptr) {
            counter++;
            current = current->next;
        }

        return counter;
    }
```

Результат:

```
10 -> 30 -> nullptr

2
```


Метод проходить по всіх елементах списку, тому має **часову складність O(n)**, 
і використовує константну **памʼять O(1)**.


### Завдання 3: Перевертання списку – reverse:

```
    void reverse() {

        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;  
            prev = current;     
            current = nextNode;   
        }

        head = prev;
    }
```

Результат виконання:

```
10 -> 30 -> 20 -> 30 -> nullptr
30 -> 20 -> 30 -> 10 -> nullptr
```


Метод reverse має **часову складність O(n)**, оскільки потрібно пройти по кожному вузлу списку один раз. 
**Просторова складність — O(1)**, створюється лише 3 додаткові поінтери.

### Завдання 4. Визначення циклу – detectCycle:

```
    bool detectCycle() const {
        
    Node<T>* slow = head;
    Node<T>* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;          
        fast = fast->next->next;  

        if (slow == fast) {
            return true;
        }
    }

    return false;  
    
    }
```

Результат виконання:

```
30 -> 20 -> 30 -> 10 -> nullptr

0
```

Метод має **лінійну складність O(n)**, оскільки кожен вузол проходиться максимум двічі
**Просторова склідність - O(1)** – не використовується додаткових структур.


### Завдання 5: N-й елемент з кінця – getNthFromEnd

```
    Node<T>* getNthFromEnd(size_t n) const {
    Node<T>* slow = head;
    Node<T>* fast = head;

    for (size_t i = 0; i < n; i++) {
        if (fast == nullptr) return nullptr; 
        fast = fast->next;
    };

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    };

    return slow;

```
Результат (параметр 2):

```
10 -> 30 -> 20 -> 30 -> 40 -> 50 -> nullptr

40
```

Складність алгоритму - **лінійна O(n)**,  кожен вузол проходиться максимум двічі.
**Просторова O(1)** – не використовується додаткових структур

