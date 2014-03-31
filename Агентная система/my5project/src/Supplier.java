public class Supplier { 
    
    private Factory factory;
    
    public Supplier() {
        factory = Factory.getInstance();
    }
    
    public void supply () {
        factory.increaseMaterials();
        System.out.println("���������: � ������ ��������!");
        System.out.println("�������: " + factory.getGoods() + ", ����������: " + factory.getMaterials());
    }
}
