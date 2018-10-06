interface Actions {
    Object move();
    Object sleep();
    Object eat();
}

class Human implements Actions {
    @Override
    public Object move() {
        return new Object();
    }

    @Override
    public Object sleep() {
        return new Object();
    }

    @Override
    public Object eat() {
        return new Object();
    }
}

public class Adapter {
    private Human h = new Human();

    public Object move() {
        return h.move();
    }

    public Object sleep() {
        return h.sleep();
    }

    public Object eat() {
        return h.eat();
    }
}

