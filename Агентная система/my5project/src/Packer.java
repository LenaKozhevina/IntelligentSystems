public class Packer {
    
    private Factory factory;
    
    public Packer() {
        factory = Factory.getInstance();
    }
    
    public void recieve() {
        if (factory.getGoods() > 0) {
            factory.decreaseGoods();
            System.out.println("���������: ����� ������ � ������ ��������!");
        } else {
            System.out.println("���������: ��� ������!");
        }
        System.out.println("�������: " + factory.getGoods() + ", ����������: " + factory.getMaterials());
    }
    
}
