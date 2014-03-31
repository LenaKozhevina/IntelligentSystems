public class Manufacturer {
    
    private Factory factory;
    
    public Manufacturer() {
        factory = Factory.getInstance();
    }
    
    public void produce() {
        if (factory.getMaterials() > 0) {
            factory.decreaseMaterials();
            factory.increaseGoods();
            System.out.println("�������������: � �������� �����!");
        } else {
            System.out.println("�������������: ��� ��������� ��� ������������!");
        }
        System.out.println("�������: " + factory.getGoods() + ", ����������: " + factory.getMaterials());
    }
}
