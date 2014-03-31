public class Packer {
    
    private Factory factory;
    
    public Packer() {
        factory = Factory.getInstance();
    }
    
    public void recieve() {
        if (factory.getGoods() > 0) {
            factory.decreaseGoods();
            System.out.println("Упаковщик: Товар принят в службу доставки!");
        } else {
            System.out.println("Упаковщик: Нет товара!");
        }
        System.out.println("Товаров: " + factory.getGoods() + ", материалов: " + factory.getMaterials());
    }
    
}
