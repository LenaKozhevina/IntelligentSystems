public class Supplier { 
    
    private Factory factory;
    
    public Supplier() {
        factory = Factory.getInstance();
    }
    
    public void supply () {
        factory.increaseMaterials();
        System.out.println("Поставщик: Я привез материал!");
        System.out.println("Товаров: " + factory.getGoods() + ", материалов: " + factory.getMaterials());
    }
}
