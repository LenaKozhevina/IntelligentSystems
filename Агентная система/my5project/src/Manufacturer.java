public class Manufacturer {
    
    private Factory factory;
    
    public Manufacturer() {
        factory = Factory.getInstance();
    }
    
    public void produce() {
        if (factory.getMaterials() > 0) {
            factory.decreaseMaterials();
            factory.increaseGoods();
            System.out.println("Производитель: Я произвел товар!");
        } else {
            System.out.println("Производитель: Нет материала для производства!");
        }
        System.out.println("Товаров: " + factory.getGoods() + ", материалов: " + factory.getMaterials());
    }
}
