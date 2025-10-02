# Design Patterns in C++

A comprehensive collection of software design patterns implemented in C#. This repository demonstrates the classic Gang of Four design patterns, providing clear examples and explanations for each pattern.

## Table of Contents

- [Creational Patterns](#creational-patterns)
- [Structural Patterns](#structural-patterns)
- [Behavioral Patterns](#behavioral-patterns)

---

## Creational Patterns

Creational patterns focus on object creation mechanisms, providing flexibility in what gets created, who creates it, how it gets created, and when. These patterns abstract the instantiation process and help make systems independent of how objects are created, composed, and represented.

### Builder Pattern

**Purpose:** Separates the construction of a complex object from its representation, allowing the same construction process to create different representations.

**Participants:**
- **Builder:** Abstract interface for creating parts of a Product
- **ConcreteBuilder:** Implements the Builder interface and constructs/assembles parts
- **Director:** Constructs an object using the Builder interface
- **Product:** The complex object being built

**Use Cases:**
1. **Document Converter:** Building different document formats (PDF, HTML, Plain Text) from the same source data, where each format requires different construction steps.
2. **Meal Builder:** Creating customized meals at a restaurant where you can build different types of meals (vegetarian, vegan, standard) with various combinations of items (burger, drink, side, dessert).

---

### Factory Method Pattern

**Purpose:** Defines an interface for creating an object but lets subclasses decide which class to instantiate, deferring instantiation to subclasses.

**Participants:**
- **Product:** Interface for objects the factory method creates
- **ConcreteProduct:** Implements the Product interface
- **Creator:** Declares the factory method
- **ConcreteCreator:** Overrides factory method to return ConcreteProduct

**Use Cases:**
1. **Logistics System:** A logistics company with different transport types (Truck, Ship, Plane) where each delivery method requires a different vehicle object but follows the same delivery interface.
2. **GUI Framework:** Creating platform-specific UI elements (Windows buttons, Mac buttons, Linux buttons) where each platform needs different implementations but the same interface.

---

### Prototype Pattern

**Purpose:** Creates new objects by copying existing objects (prototypes), avoiding the overhead of creating objects from scratch.

**Participants:**
- **Prototype:** Interface declaring the clone method
- **ConcretePrototype:** Implements the clone operation
- **Client:** Creates new objects by asking a prototype to clone itself

**Use Cases:**
1. **Game Development:** Cloning game characters or enemies with predefined configurations instead of initializing them from scratch each time.
2. **Document Templates:** Creating new documents based on existing templates (invoices, reports, contracts) where each clone can be modified independently.

---

## Structural Patterns

Structural patterns deal with object composition, creating relationships between objects to form larger, more complex structures. They help ensure that when one part changes, the entire structure doesn't need to change.

### Composite Pattern

**Purpose:** Composes objects into tree structures to represent part-whole hierarchies, allowing clients to treat individual objects and compositions uniformly.

**Participants:**
- **Component:** Interface for objects in the composition
- **Leaf:** Represents leaf objects with no children
- **Composite:** Stores child components and implements child-related operations
- **Client:** Manipulates objects through the Component interface

**Use Cases:**
1. **File System:** Representing files and folders where both individual files and folders containing files/subfolders can be treated uniformly for operations like size calculation or searching.
2. **Organization Chart:** Modeling company hierarchies where both individual employees and departments (containing employees/sub-departments) can be processed the same way.

---

### Decorator Pattern

**Purpose:** Attaches additional responsibilities to an object dynamically, providing a flexible alternative to subclassing for extending functionality.

**Participants:**
- **Component:** Interface for objects that can have responsibilities added
- **ConcreteComponent:** Object to which additional responsibilities can be attached
- **Decorator:** Maintains reference to Component and conforms to Component interface
- **ConcreteDecorator:** Adds responsibilities to the component

**Use Cases:**
1. **Coffee Shop:** Adding condiments (milk, sugar, whipped cream, caramel) to a base coffee where each addition modifies the cost and description dynamically.
2. **Text Formatting:** Adding formatting features (bold, italic, underline, color) to text components where multiple decorations can be stacked.

---

## Behavioral Patterns

Behavioral patterns focus on communication between objects, defining how objects interact and distribute responsibility. They help make the communication more flexible and easier to maintain.

### Command Pattern

**Purpose:** Encapsulates a request as an object, allowing parameterization of clients with different requests, queuing of requests, and logging of operations.

**Participants:**
- **Command:** Interface declaring the execute method
- **ConcreteCommand:** Implements execute by invoking operations on Receiver
- **Invoker:** Asks the command to carry out the request
- **Receiver:** Knows how to perform the operations
- **Client:** Creates ConcreteCommand and sets its Receiver

**Use Cases:**
1. **Text Editor:** Implementing undo/redo functionality where each user action (type, delete, format) is a command that can be executed, undone, or redone.
2. **Smart Home System:** Controlling various devices (lights, thermostat, doors) through a unified remote control interface where each button press executes a specific command.

---

### Iterator Pattern

**Purpose:** Provides a way to access elements of a collection sequentially without exposing the underlying representation.

**Participants:**
- **Iterator:** Interface for accessing and traversing elements
- **ConcreteIterator:** Implements Iterator and keeps track of current position
- **Aggregate:** Interface for creating an Iterator
- **ConcreteAggregate:** Implements Iterator creation

**Use Cases:**
1. **Social Media Feed:** Traversing through posts, comments, or user lists where the underlying data structure (array, tree, graph) is hidden from the client.
2. **Playlist Manager:** Iterating through songs in different orders (sequential, shuffle, filtered by genre) without exposing how the playlist is stored internally.

---

### Mediator Pattern

**Purpose:** Defines an object that encapsulates how a set of objects interact, promoting loose coupling by preventing objects from referring to each other explicitly.

**Participants:**
- **Mediator:** Interface for communicating with Colleague objects
- **ConcreteMediator:** Coordinates communication between colleagues
- **Colleague:** Each colleague class knows its Mediator
- **ConcreteColleague:** Communicates with other colleagues through the mediator

**Use Cases:**
1. **Chat Room:** Managing communication between multiple users where users don't send messages directly to each other but through a central chat room coordinator.
2. **Air Traffic Control:** Coordinating communication between aircraft where planes don't communicate directly with each other but through the control tower to avoid collisions.

---

### Memento Pattern

**Purpose:** Captures and externalizes an object's internal state without violating encapsulation, allowing the object to be restored to this state later.

**Participants:**
- **Memento:** Stores internal state of Originator
- **Originator:** Creates memento and uses it to restore state
- **Caretaker:** Responsible for memento's safekeeping

**Use Cases:**
1. **Game Save System:** Saving player progress, inventory, and position at checkpoints, allowing players to load previous game states.
2. **Drawing Application:** Implementing undo functionality in graphic editors where canvas state snapshots are saved before each drawing operation.

---

### Observer Pattern

**Purpose:** Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

**Participants:**
- **Subject:** Knows its observers and provides interface for attaching/detaching
- **Observer:** Interface for objects that should be notified of changes
- **ConcreteSubject:** Stores state and sends notifications to observers
- **ConcreteObserver:** Maintains reference to ConcreteSubject and implements update

**Use Cases:**
1. **News Subscription:** When a news agency publishes an article, all subscribed readers (email, mobile app, RSS) are automatically notified.
2. **Stock Market Monitor:** When stock prices change, all monitoring dashboards, alert systems, and trading algorithms are notified simultaneously.

---

### State Pattern

**Purpose:** Allows an object to alter its behavior when its internal state changes, appearing as if the object changed its class.

**Participants:**
- **Context:** Maintains instance of ConcreteState that defines current state
- **State:** Interface defining behavior associated with a state
- **ConcreteState:** Each subclass implements behavior for a particular state

**Use Cases:**
1. **Vending Machine:** Managing different states (NoMoney, HasMoney, Dispensing, OutOfStock) where button presses have different effects depending on current state.
2. **Document Workflow:** Managing document states (Draft, Review, Approved, Published) where available actions change based on the document's current state.

---

### Strategy Pattern

**Purpose:** Defines a family of algorithms, encapsulates each one, and makes them interchangeable, letting the algorithm vary independently from clients that use it.

**Participants:**
- **Strategy:** Interface common to all supported algorithms
- **ConcreteStrategy:** Implements the algorithm using the Strategy interface
- **Context:** Maintains reference to Strategy object and may define interface for Strategy to access its data

**Use Cases:**
1. **Payment Processing:** Implementing different payment methods (credit card, PayPal, cryptocurrency) where the payment strategy can be selected at runtime.
2. **Route Planning:** Calculating routes using different strategies (shortest distance, fastest time, scenic route, avoid highways) based on user preference.

---

### Template Method Pattern

**Purpose:** Defines the skeleton of an algorithm in a base class, letting subclasses override specific steps without changing the algorithm's structure.

**Participants:**
- **AbstractClass:** Defines abstract primitive operations that subclasses override
- **ConcreteClass:** Implements the primitive operations to carry out subclass-specific steps

**Use Cases:**
1. **Data Mining Application:** Processing different data formats (CSV, JSON, XML) where the overall algorithm (open file, extract data, analyze, generate report) stays the same but specific steps vary.
2. **Beverage Preparation:** Making different hot beverages (tea, coffee) where the preparation steps (boil water, brew, pour in cup, add condiments) follow the same sequence but some steps differ.

---

## Getting Started

Each pattern is contained in its own directory with a complete implementation and example usage. Navigate to individual pattern directories to explore the code and see practical examples.

## Contributing

Contributions are welcome! Feel free to submit pull requests with improvements, additional examples, or new pattern implementations.

## License

This project is open source and available for educational purposes.
