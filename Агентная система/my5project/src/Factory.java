public class Factory {
    
    private static Factory factoryInstance;
    private int goods;
    private int materials;
   
    
    
    
    private Factory() {
        goods = 0;
        materials = 0;
      
    }
    public static Factory getInstance() {
        if (factoryInstance != null) {
            return factoryInstance;
        } else {
            factoryInstance = new Factory();
            return factoryInstance;
        }
    }
    
    public int getMaterials(){
    	return materials;
    }
    
    public void increaseMaterials() {
    	materials++;
    }
    
    public void decreaseMaterials() {
    	materials--;
    }
    
    public int getGoods() {
        return goods;
    }
    
    public void increaseGoods() {
        goods++;
    }
    
    public void decreaseGoods() {
        goods--;
    }
    
    public static void main(String[] args) {
    	 Manufacturer manufacturer = new Manufacturer();
         Packer packer = new Packer();
         Supplier supplier = new Supplier();
          
        supplier.supply();
        manufacturer.produce();
        packer.recieve();
        
    }
}
